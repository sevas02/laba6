//ѕрограмма решает систему из двух уравнений, наход€ матрицы A и B
//дл€ системы 3A - B = C1 и 6A + B = C2
#include <iostream>
#include <iomanip>
#include "matrix.h"
#include "correct_input.h"
using namespace std;

int main() {
	setlocale(0, "RUS");
	int n, m;
	cout << "The program solves a system of two equations, finding matrices A and B!\n";
	cout << "Given a system:\n{3A - B = C1\n|\n{6A + B = C2\n";
	cout << "Enter the dimension of the matrices:";
	correct_input_N(n);
	correct_input_N(m);
	double ** A_matrix = matrix_nul_create(n, m);
	double ** B_matrix = matrix_nul_create(n, m);
	cout << "Enter matrix C1: \n";
	double ** C1_matrix = matrix_input(n, m);
	cout << "Enter matrix C2:\n";
	double ** C2_matrix = matrix_input(n, m);
	cout << "______________________\n";
	cout << "\nMatrix C1:\n";
	matrix_output(C1_matrix, n, m);
	cout << "\nMatrix C1:\n";
	matrix_output(C2_matrix, n, m);
	cout << "______________________\n";
	matrix_system_solution(A_matrix, B_matrix, C1_matrix, C2_matrix, n, m);
	cout << "========Answer========\n";
	cout << "\nMatrix A = \n";
	matrix_output(A_matrix, n, m);
	cout << "\nMatrix B = \n";
	matrix_output(B_matrix, n, m);
	cout << "======================\n";
	matrix_memory_clear(A_matrix, n);
	matrix_memory_clear(B_matrix, n);
	matrix_memory_clear(C1_matrix, n);
	matrix_memory_clear(C2_matrix, n);
	return 0;
}