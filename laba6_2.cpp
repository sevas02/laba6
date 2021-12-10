//нахождение определителя матрицы по первому столбцу
#include <iostream>
#include <iomanip>
#include "matrix.h"
#include "correct_input.h"
using namespace std;

int main() {
	setlocale(0, "RUS");
	int n;
	double det = 0;
	cout << "Please, enter the size of a square matrix A: ";
	correct_input_N(n);
	cout << "Enter the matrix A: \n";
	double ** original_matrix = matrix_input(n);
	det = matrix_det(original_matrix, n);
	cout << "Determinant of a matrix A = " << det;
	matrix_memory_clear(original_matrix, n);
	return 0;
}