#include "matrix.h"
#include "correct_input.h"
#include <iostream>
#include <iomanip>
using namespace std;

//�������� ������� ���������� �������
double** sqr_matrix_nul_create(int n) {
	double** out_matr = new double*[n];
	for (int i = 0; i < n; i++)
		out_matr[i] = new double[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			out_matr[i][j] = 0;
	return out_matr;
}

//�������� ������ ����� �������� �������
void matrix_memory_clear(double** matr, int n) {
	for (int i = 0; i < n; i++)
		delete[] matr[i];
	delete[] matr;
}

//���� ���������� �������
double** sqr_matrix_input(int n) {
	double** orig_matr = sqr_matrix_nul_create(n);
	double element;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cout << "A[" << i + 1 << "][" << j + 1 << "] = ";
			correct_input_R(element);
			orig_matr[i][j] = element;
		}
	return orig_matr;
}

//����� ���������� �������
void sqr_matrix_output(double** orig_matr, int n) {
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << setw(10) << fixed << setprecision(0) << orig_matr[i][j];
		cout << endl;
	}
}

//������� �������� ���������� ������� � ������
double** sqr_matrix_addition_num(double** matr, int n, int num) {
	double** out_matr = sqr_matrix_nul_create(n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == j)
				out_matr[i][j] = num + matr[i][j];
			else
				out_matr[i][j] = matr[i][j];
		}
	return out_matr;
}

//������� ��������� ���������� ������� �� �����
double** sqr_matrix_multiply_num(double** matr, int n, int num) {
	double** out_matr = sqr_matrix_nul_create(n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			out_matr[i][j] = num * matr[i][j];
	return out_matr;
}

//������� �������� ���������� ������
double** sqr_matrix_addition_matrix(double** matr_1, double** matr_2, int n) {
	double** out_matr = sqr_matrix_nul_create(n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			out_matr[i][j] = matr_1[i][j] + matr_2[i][j];
	return out_matr;
}

//������� ������������ ���������� ������
double** sqr_matrix_multiply_matrix(double** matr_1, double** matr_2, int n) {
	double** out_matr = sqr_matrix_nul_create(n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				out_matr[i][j] += matr_1[i][k] * matr_2[k][j];
	return out_matr;
}

//������ ������� X = A^2
double** sqr_matrix_pow_2(double** orig_matr, int n) {
	double** out_matr = sqr_matrix_nul_create(n);

	out_matr = sqr_matrix_multiply_matrix(orig_matr, orig_matr, n);
	return out_matr;
}

//������ ������� f(x) = 3*x^3 + 5*x^2 + x - 2. 
double** function_calculation(double** x_matr, int n) {
	cout << "\n\n���������� ��������� f(x) = 3*x^3 + 5*x^2 + x - 2";
	cout << "\nx^2 = \n";
	double** x_pow_2 = sqr_matrix_multiply_matrix(x_matr, x_matr, n);
	sqr_matrix_output(x_pow_2, n);
	cout << "\nx^3 = \n";
	double** x_pow_3 = sqr_matrix_multiply_matrix(x_matr, x_pow_2, n);
	sqr_matrix_output(x_pow_3, n);
	cout << "\n3*x^3 = \n";
	double** first_term = sqr_matrix_multiply_num(x_pow_3, n, 3);
	sqr_matrix_output(first_term, n);
	cout << "\n5*x^2 = \n";
	double** second_term = sqr_matrix_multiply_num(x_pow_2, n, 5);
	sqr_matrix_output(second_term, n);
	cout << "\n3*x^3 + 5*x^2 = \n";
	double** first_sum = sqr_matrix_addition_matrix(first_term, second_term, n);
	sqr_matrix_output(first_sum, n);
	cout << "\n3*x^3 + 5*x^2 + x = \n";
	double** second_sum = sqr_matrix_addition_matrix(first_sum, x_matr, n);
	sqr_matrix_output(second_sum, n);
	cout << "\n3*x^3 + 5*x^2 + x - 2 = \n";
	double** resoult = sqr_matrix_addition_num(second_sum, n, -2);

	matrix_memory_clear(x_pow_2, n);
	matrix_memory_clear(x_pow_3, n);
	matrix_memory_clear(first_term, n);
	matrix_memory_clear(second_term, n);
	matrix_memory_clear(first_sum, n);
	matrix_memory_clear(second_sum, n);
	return resoult;
}

//���������� ������� ��� ���������� ������, ����� ������������� row-�� ������ � col-���� ������� ������� matr;
void matrix_for_minor(double **matr, int n, int row, int col, double **minor_matr) {
	int row_shift = 0; //�������� ������� ������ � �������
	int col_shift = 0; //�������� ������� ������� � �������
	for (int i = 0; i < n - 1; i++) {
		//���������� row-�� ������
		if (i == row)
			row_shift = 1;
		for (int j = 0; j < n - 1; j++) {
			//���������� col-�� �������
			if (j == col)
				col_shift = 1;
			minor_matr[i][j] = matr[i + row_shift][j + col_shift];
		}
	}
}

//����������� ������� ��� ���������� ������������ �������. 
int matrix_det(double** matr, int n) {
	//��������� �������, ���������� ������������� i-�� ������ � 0-��� �������
	double** temp = sqr_matrix_nul_create(n - 1);
	double det = 0;
	double alg_dop = 0;
	//���� ����� �� ������ 2�2, �� ����������� ���
	if (n == 2) {
		alg_dop = matr[0][0] * matr[1][1] - matr[0][1] * matr[1][0];
		return alg_dop;
	}
	//������� ������ �� ��������
	if (n == 1) {
		return matr[0][0];
	}
	//���� ��� ������������ ��������������� ����������
	int sign = 1;
	for (int i = 0; i < n; i++) {
		//������� �� ������� i-�� ������ � 0-�� �������
		matrix_for_minor(matr, n, i, 0, temp);

		double minor = matrix_det(temp, n - 1);
		alg_dop = (sign * matr[i][0] * minor);

		//������� ����� i-��, 0-��
		//sqr_matrix_output(temp, n - 1);
		//cout << endl;
		//��������� �����
		//cout << sign << " * " << matr[i][0] << " * " << minor << " = " << alg_dop << endl << endl;

		//������ ����
		sign *= -1;
		det += alg_dop;
	}
	matrix_memory_clear(temp, n - 1);
	return det;
}

//�������� ������� ������� ������ �������
double** matrix_nul_create(int n, int m) {
	double** out_matr = new double*[n];
	for (int i = 0; i < n; i++)
		out_matr[i] = new double[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			out_matr[i][j] = 0;
	return out_matr;
}

//�������� ��������� ������� 
double** unit_matrix(int n) {
	double** out_matr = new double*[n];
	for (int i = 0; i < n; i++)
		out_matr[i] = new double[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j)
				out_matr[i][j] = 0;
			else
				out_matr[i][j] = 1;
	return out_matr;
}

//���� ������� ������ �������
double** matrix_input(int n, int m) {
	double** orig_matr = matrix_nul_create(n, m);
	double element;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cout << "A[" << i + 1 << "][" << j + 1 << "] = ";
			correct_input_R(element);
			orig_matr[i][j] = element;
		}
	return orig_matr;
}

//����� ������� ������ �������
void matrix_output(double** orig_matr, int n, int m) {
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << setw(10) << fixed << setprecision(0) << orig_matr[i][j];
		cout << endl;
	}
}

//������� ��������� ������� ������ ������� �� �����
double** matrix_multiply_num(double** matr, int n, int m, int num) {
	double** out_matr = matrix_nul_create(n, m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			out_matr[i][j] = num * matr[i][j];
	return out_matr;
}

//������� �������� ������ ������ �������
double** matrix_addition_matrix(double** matr_1, double** matr_2, int n, int m) {
	double** out_matr = matrix_nul_create(n, m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			out_matr[i][j] = matr_1[i][j] + matr_2[i][j];
	return out_matr;
}

//������� ������������ ������
double** matrix_multiply_matrix(double** matr_1, int n1, int m1, double** matr_2, int n2, int m2) {
	if (m1 != n2) {
		cout << "��������� ��������� ����������, ��� �����!";
		return 0;
	}
	double** out_matr = matrix_nul_create(n1, m2);
	for (int i = 0; i < n1; i++)
		for (int j = 0; j < m2; j++)
			for (int k = 0; k < m1; k++)
				out_matr[i][j] += matr_1[i][k] * matr_2[k][j];
	return out_matr;
}

//���������� �������� �-�� ����������
double** matrix_inverse(double** matr, int n) {
	int det = matrix_det(matr, n);
	if (det == 0)
	{
		cout << "\n������������ ����� 0. ������� ��� �������� �-�� ��� ��� ���������� �����";
		return 0;
	}

	double** inverse_matr = sqr_matrix_nul_create(n);
	//��������� �������, ���������� ������������� i-�� ������ � 0-��� �������
	double** temp = sqr_matrix_nul_create(n - 1);
	int sign = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			matrix_for_minor(matr, n, i, 0, temp);
			inverse_matr[i][j] = (1 / det) * sign * matrix_det(temp, n - 1);
			if (abs(inverse_matr[i][j]) < 0.000000000001) 
				inverse_matr[i][j] = 0;
		}

	return inverse_matr;
}

//������� ������� ������
void matrix_system_solution(double** &matr_A, double** &matr_B, double** matr_C1, double** matr_C2, int n, int m) {
	cout << "�������� ������� B:\nB = C2 - 6A\n";
	cout << "����������� ������� B � ������ ��������� � ��������:\n3A - C2 + 6A = C1\n";
	cout << "���� ��������������, ��������:\nA(3+6) = C1 + C2 ---> A = (C1 + C2) * (3 + 6)\n";
	//(3+6)A = �2 + �1
	cout << "______________________\n";
	cout << "����� ������ C1 + C2 = \n";
	double** C1_add_C2 = matrix_addition_matrix(matr_C1, matr_C2, n, m);
	matrix_output(C1_add_C2, n, m);
	cout << "______________________\n";
	//�������� ��������� ������� ��� 3+6
	cout << "______________________\n";
	cout << "A = (�1 + C2) * (3 + 6) * E = \n";
	matrix_output(C1_add_C2, n, m);
	cout << " * ";
	double** temp_matr = unit_matrix(m);
	temp_matr = matrix_multiply_num(temp_matr, m, m, 9);
	matrix_output(temp_matr, m, m);
	cout << "______________________\n";
	//������� ������� �
	cout << "______________________\n";
	cout << "����� ������� � = \n";
	matr_A = matrix_multiply_matrix(C1_add_C2, n, m, temp_matr, m, m);
	matrix_output(matr_A, n, m);
	cout << "______________________\n";
	//����� ��������� 3A - B = �1
	//������� 3A
	cout << "������� ������� � ����� ������ ���������:\nB = 3A - C1\n";
	cout << "______________________\n";
	cout << "������� 3*A = \n";
	double** A_to_3A = matrix_multiply_num(matr_A, n, m, 3);
	matrix_output(A_to_3A, n, m);
	cout << "______________________\n";
	//������� -C1
	double** minus_matr_C1 = matrix_multiply_num(matr_C1, n, m, -1);
	cout << "______________________\n";
	cout << "3A - C1 = \n";
	matrix_output(A_to_3A, n, m);
	cout << " + ";
	matrix_output(minus_matr_C1, n, m);
	cout << "______________________\n";
	//������� ������� B
	matr_B = matrix_addition_matrix(A_to_3A, minus_matr_C1, n, m);
	
	matrix_memory_clear(C1_add_C2, n);
	matrix_memory_clear(temp_matr, m);
	matrix_memory_clear(A_to_3A, n);
	matrix_memory_clear(minus_matr_C1, n);
}
