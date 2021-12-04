#include <iostream>
#include <iomanip>
#include "matrix_operations.h"
#include "correct_input.h"
using namespace std;

int main() {
	setlocale(0, "RUS");
	int n;
	cout << "¬ведите размерность квадратной матрицы A: ";
	correct_input_N(n);
	cout << "¬ведите матрицу A: \n";
	double ** original_matrix = matrix_input(n);
	double ** resoult_matrix = func_calc(original_matrix, n);
	clear_memory_after_matrix(original_matrix, n);
	clear_memory_after_matrix(resoult_matrix, n);
	return 0;
}