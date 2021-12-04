#include "matrix_operations.h"
#include "correct_input.h"
#include <iostream>
#include <iomanip>
using namespace std;

//создание нулевой матрицы
double** matrix_nul(int n) {
	double** out_matr = new double*[n];
	for (int i = 0; i < n; i++)
		out_matr[i] = new double[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			out_matr[i][j] = 0;

	return out_matr;
}

//отчистка памяти после создания матрицы
void clear_memory_after_matrix(double** matr, int n) {
	for (int i = 0; i < n; i++)
		delete[] matr[i];
	delete[] matr;
}

//ввод начальной матрицы
double** matrix_input(int n) {
	double** orig_matr = matrix_nul(n);
	double element;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cout << "A[" << i + 1 << "][" << j + 1 << "] = ";
			correct_input_R(element);
			orig_matr[i][j] = element;
		}
	return orig_matr;
}

//вывод начальной матрицы
void matrix_output(double** orig_matr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << setw(10) << fixed << setprecision(0) << orig_matr[i][j];
		cout << endl;
	}
}
 
//функция сложения матрицы с числом
double** matrix_addition_num(double** matr, int num, int n) {
	double** out_matr = matrix_nul(n);
	
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) {
			if (i == j)
				out_matr[i][j] = num + matr[i][j];
			else
			out_matr[i][j] = matr[i][j];
		}
	cout << endl;
	matrix_output(out_matr, n); //вывод для проверки че получилось
	return out_matr;
}

//функция умножения матрицы на число
double** matrix_multiply_num(double** matr, int num, int n) {
	double** out_matr = matrix_nul(n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
			out_matr[i][j] = num * matr[i][j];
	cout << endl;
	matrix_output(out_matr, n);
	return out_matr;
}

//функция сложения матриц
double** matrix_addition_matrix(double** matr_1, double** matr_2, int n) {
	double** out_matr = matrix_nul(n);

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++)
			out_matr[i][j] = matr_1[i][j] + matr_2[i][j];
	
	cout << endl;
	matrix_output(out_matr, n);
	return out_matr;
}

//функция перемножения матриц
double** matrix_multiply_matrix(double** matr_1, double** matr_2, int n) {
	double** out_matr = matrix_nul(n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				out_matr[i][j] += matr_1[i][k] * matr_2[k][j];

	cout << endl;
	matrix_output(out_matr, n);
	return out_matr;
}

//расчёт функции f(x) = 3*x^3 + 5*x^2 + x - 2. при f(A^2)
double** func_calc(double** orig_matr, int n) {
	cout << "\nПосчитаем выражение f(x) = 3*x^3 + 5*x^2 + x - 2; при f(A^2)\n";
	cout << "\nA^2 = ";
	orig_matr = matrix_multiply_matrix(orig_matr, orig_matr, n);
	cout << "\nx^2 = ";
	double** x_pow_2 = matrix_multiply_matrix(orig_matr, orig_matr, n);
	cout << "\nx^3 = ";
	double** x_pow_3 = matrix_multiply_matrix(orig_matr, x_pow_2, n);
	cout << "\n3*x^3 = ";
	double** first_term = matrix_multiply_num(x_pow_3, 3, n);
	cout << "\n5*x^2 = ";
	double** second_term = matrix_multiply_num(x_pow_2, 5, n);
	cout << "\n3*x^3 + 5*x^2 = ";
	double** first_sum = matrix_addition_matrix(first_term, second_term, n);
	cout << "\n3*x^3 + 5*x^2 + x = ";
	double** second_sum = matrix_addition_matrix(first_sum, orig_matr, n);
	cout << "\n3*x^3 + 5*x^2 + x - 2 = ";
	double** resoult = matrix_addition_num(second_sum, -2, n); 

	clear_memory_after_matrix(x_pow_2, n);
	clear_memory_after_matrix(x_pow_3, n);
	clear_memory_after_matrix(first_term, n);
	clear_memory_after_matrix(second_term, n);
	clear_memory_after_matrix(first_sum, n);
	clear_memory_after_matrix(second_sum, n);
	return resoult;
}



