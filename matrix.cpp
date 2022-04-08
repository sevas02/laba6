#include "matrix.h"
#include "correct_input.h"
#include <iostream>
#include <iomanip>
using namespace std;

//создание нулевой квадратной матрицы
double** sqr_matrix_nul_create(int n) {
	double** out_matr = new double* [n];
	for (int i = 0; i < n; i++)
		out_matr[i] = new double[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			out_matr[i][j] = 0;
	return out_matr;
}

//отчистка памяти после создания матрицы
void matrix_memory_clear(double** matr, int n) {
	for (int i = 0; i < n; i++)
		delete[] matr[i];
	delete[] matr;
}

//ввод квадратной матрицы
double** sqr_matrix_input(int n) {
	double** orig_matr = sqr_matrix_nul_create(n);
	double element;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cout << "[" << i + 1 << "][" << j + 1 << "] = ";
			correct_input_R(element);
			orig_matr[i][j] = element;
		}
	return orig_matr;
}

//вывод квадратной матрицы
void sqr_matrix_output(double** orig_matr, int n) {
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << setw(10) << fixed << setprecision(0) << orig_matr[i][j];
		cout << endl;
	}
}

//функция сложения квадратной матрицы с числом
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

//функция умножения квадратной матрицы на число
double** sqr_matrix_multiply_num(double** matr, int n, int num) {
	double** out_matr = sqr_matrix_nul_create(n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			out_matr[i][j] = num * matr[i][j];
	return out_matr;
}

//функция сложения квадратных матриц
double** sqr_matrix_addition_matrix(double** matr_1, double** matr_2, int n) {
	double** out_matr = sqr_matrix_nul_create(n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			out_matr[i][j] = matr_1[i][j] + matr_2[i][j];
	return out_matr;
}

//функция перемножения квадратных матриц
double** sqr_matrix_multiply_matrix(double** matr_1, double** matr_2, int n) {
	double** out_matr = sqr_matrix_nul_create(n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				out_matr[i][j] += matr_1[i][k] * matr_2[k][j];
	return out_matr;
}

//расчёт матрицы X = A^2
double** sqr_matrix_pow_2(double** orig_matr, int n) {
	double** out_matr = sqr_matrix_nul_create(n);

	out_matr = sqr_matrix_multiply_matrix(orig_matr, orig_matr, n);
	return out_matr;
}

//расчёт функции f(x) = 3*x^3 + 5*x^2 + x - 2. 
double** function_calculation(double** x_matr, int n) {
	cout << "\n\nПодсчитаем выражение f(x) = 3*x^3 + 5*x^2 + x - 2";
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

//Возвращает матрицу для нахождения минора, путем вырчеркивания row-ой строки и col-того столбца матрицы matr;
void matrix_for_minor(double** matr, int n, int row, int col, double** minor_matr) {
	int row_shift = 0; //Смещение индекса строки в матрице
	int col_shift = 0; //Смещение индекса столбца в матрице
	for (int i = 0; i < n - 1; i++) {
		//Пропустить row-ую строку
		if (i == row)
			row_shift = 1;
		for (int j = 0; j < n - 1; j++) {
			//Пропустить col-ый столбец
			if (j == col)
				col_shift = 1;
			minor_matr[i][j] = matr[i + row_shift][j + col_shift];
		}
	}
}

//Рекурсивная функция для нахождения определителя матрицы. 
int matrix_det(double** matr, int n) {
	//временная матрица, полученная вычеркиванием i-ой строки и 0-ого столбца
	double** temp = sqr_matrix_nul_create(n - 1);
	double det = 0;
	double alg_dop = 0;
	//если дошли до минора 2х2, то возвращаекм его
	if (n == 2) {
		alg_dop = matr[0][0] * matr[1][1] - matr[0][1] * matr[1][0];
		return alg_dop;
	}
	//условие выхода из рекурсии
	if (n == 1) {
		return matr[0][0];
	}
	//знак для высчитывания алгебраического дополнения
	int sign = 1;
	for (int i = 0; i < n; i++) {
		//Удаляем из матрицы i-ую строку и 0-ый столбец
		matrix_for_minor(matr, n, i, 0, temp);

		double minor = matrix_det(temp, n - 1);
		alg_dop = (sign * matr[i][0] * minor);

		//выводим минор i-ой, 0-ый
		sqr_matrix_output(temp, n - 1);
		cout << endl;
		//пошаговый вывод
		cout << sign << " * " << matr[i][0] << " * " << minor << " = " << alg_dop << endl << endl;

		//меняем знак
		sign *= -1;
		det += alg_dop;
	}
	matrix_memory_clear(temp, n - 1);
	return det;
}

//создание нулевой матрицы любого размера
double** matrix_nul_create(int n, int m) {
	double** out_matr = new double* [n];
	for (int i = 0; i < n; i++)
		out_matr[i] = new double[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			out_matr[i][j] = 0;
	return out_matr;
}

//создание еденичной матрицы 
double** unit_matrix(int n) {
	double** out_matr = new double* [n];
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

//ввод матрицы любого размера
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

//вывод матрицы любого размера
void matrix_output(double** orig_matr, int n, int m) {
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << setw(10) << fixed << setprecision(0) << orig_matr[i][j];
		cout << endl;
	}
}

//функция умножения матрицы любого размера на число
double** matrix_multiply_num(double** matr, int n, int m, int num) {
	double** out_matr = matrix_nul_create(n, m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			out_matr[i][j] = num * matr[i][j];
	return out_matr;
}

//функция сложения матриц любого размера
double** matrix_addition_matrix(double** matr_1, double** matr_2, int n, int m) {
	double** out_matr = matrix_nul_create(n, m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			out_matr[i][j] = matr_1[i][j] + matr_2[i][j];
	return out_matr;
}

//функция перемножения матриц
double** matrix_multiply_matrix(double** matr_1, int n1, int m1, double** matr_2, int n2, int m2) {
	if (m1 != n2) {
		cout << "Выполнить умножение невозможно, учи алгем!";
		return 0;
	}
	double** out_matr = matrix_nul_create(n1, m2);
	for (int i = 0; i < n1; i++)
		for (int j = 0; j < m2; j++)
			for (int k = 0; k < m1; k++)
				out_matr[i][j] += matr_1[i][k] * matr_2[k][j];
	return out_matr;
}

//вычисление обратной м-цы квадратной
double** matrix_inverse(double** matr, int n) {
	int det = matrix_det(matr, n);
	if (det == 0)
	{
		cout << "\nОпределитель равен 0. Решений для обратной м-цы нет или бесконечно много";
		return 0;
	}

	double** inverse_matr = sqr_matrix_nul_create(n);
	//временная матрица, полученная вычеркиванием i-ой строки и 0-ого столбца
	double** temp = sqr_matrix_nul_create(n - 1);
	int sign = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			matrix_for_minor(matr, n, i, 0, temp);
			inverse_matr[i][j] = (1 / det) * sign * matrix_det(temp, n - 1);
			if (abs(inverse_matr[i][j]) < 0.000000000001)
				inverse_matr[i][j] = 0;
		}

	return inverse_matr;
}

//решение системы матриц
void matrix_system_solution(double**& matr_A, double**& matr_B, double** matr_C1, double** matr_C2, int n, int m) {
	cout << "Выражаем матрицу B:\nB = B' - 6A\n";
	cout << "Подставляем матрицу B в первое уравнение и получаем:\n3A - B' + 6A = C1\n";
	cout << "Путём преобразований, получаем:\nA(3+6) = A' + B' ---> A = (A' + B') * 1/(3 + 6)\n";//
	//(3+6)A = С2 + С1
	cout << "______________________\n";
	cout << "Сумма матриц A' + B' = \n";
	double** C1_add_C2 = matrix_addition_matrix(matr_C1, matr_C2, n, m);
	matrix_output(C1_add_C2, n, m);
	cout << "______________________\n";
	//получаем еденичную матрицу для 3+6
	cout << "______________________\n";
	cout << "A = (A' + B') * 1/(3 + 6) * E = \n";
	matrix_output(C1_add_C2, n, m);
	cout << " * ";
	double** temp_matr = unit_matrix(m);
	temp_matr = matrix_multiply_num(temp_matr, m, m, 9);//
	matrix_output(temp_matr, m, m);
	cout << "______________________\n";
	//находим матрицу А
	cout << "______________________\n";
	cout << "Нашли матрицу А = \n";
	matr_A = matrix_multiply_matrix(C1_add_C2, n, m, temp_matr, m, m);
	matrix_output(matr_A, n, m);
	cout << "______________________\n";
	//имеем выражение 3A - B = С1
	//находим 3A
	cout << "Находим матрицу В через первое уравнение:\nB = 3A - A'\n";
	cout << "______________________\n";
	cout << "Матрица 3*A = \n";
	double** A_to_3A = matrix_multiply_num(matr_A, n, m, 3);
	matrix_output(A_to_3A, n, m);
	cout << "______________________\n";
	//находим -C1
	double** minus_matr_C1 = matrix_multiply_num(matr_C1, n, m, -1);
	cout << "______________________\n";
	cout << "3A - A' = \n";
	matrix_output(A_to_3A, n, m);
	cout << " + ";
	matrix_output(minus_matr_C1, n, m);
	cout << "______________________\n";
	//находим матрицу B
	matr_B = matrix_addition_matrix(A_to_3A, minus_matr_C1, n, m);

	matrix_memory_clear(C1_add_C2, n);
	matrix_memory_clear(temp_matr, m);
	matrix_memory_clear(A_to_3A, n);
	matrix_memory_clear(minus_matr_C1, n);
}