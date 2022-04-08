#include "matrix.h"
#include "correct_input.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	setlocale(0, "RUS");
	int n;
	double det = 0;

	//Ввод матриц A и В
	cout << "Please, enter the size of a square matrix A, B: ";
	correct_input_N(n);
	cout << "Enter the matrix A: \n";
	double** a_matrix = matrix_input(n, n);
	cout << "Enter the matrix B: \n";
	double** b_matrix = matrix_input(n, n);

	//6.1 Рассчёт матриц A' и  B'
	cout << endl << "Find the matrix A' " << endl;
	double**result_matrix= sqr_matrix_addition_num(a_matrix, n, 3);
	double** new_a_matrix = function_calculation(result_matrix, n);
	sqr_matrix_output(new_a_matrix, n);
	cout << endl;
	cout << endl << "Find the matrix B' " << endl;
	result_matrix = matrix_multiply_matrix(a_matrix, n, n, b_matrix, n, n);
	double** new_b_matrix = function_calculation(result_matrix, n);
	sqr_matrix_output(new_b_matrix, n);
	cout << "\n" << "======================\n";

	//6.2 Поиск определителя матрицы A' разложением по первому столбцу
	cout << "Matrix: " << endl;
	sqr_matrix_output(new_a_matrix, n);
	cout << "\n";
	det = matrix_det(new_a_matrix, n);
	cout << "Determinant of a matrix A' = " << det << endl;
	cout << "======================\n";

	//6.3 Решение матричного уравнения.
	cout << "The program solves a system of two equations, finding matrices A and B!\n";
	cout << "Given a system:\n{3A - B = A'\n|\n{6A + B = B'\n";
	cout << "Enter matrix C1: \n";
	cout << "______________________\n";
	matrix_system_solution(a_matrix, b_matrix, new_a_matrix, new_b_matrix, n, n);
	cout << "========Answer========\n";
	cout << "\nMatrix A = \n";
	matrix_output(a_matrix, n, n);
	cout << "\nMatrix B = \n";
	matrix_output(b_matrix, n, n);
	cout << "======================\n";

	//Очистка памяти
	matrix_memory_clear(new_a_matrix, n);
	matrix_memory_clear(new_b_matrix, n);
	matrix_memory_clear(a_matrix, n);
	matrix_memory_clear(b_matrix, n);
	matrix_memory_clear(result_matrix, n);
	system("pause");
	return 0;
}