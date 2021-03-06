#include <iostream>
#include <iomanip>
#include "matrix.h"
#include "correct_input.h"
using namespace std;

int main() {
	setlocale(0, "RUS");
	int n;
	cout << "Please, enter the size of a square matrix A: ";
	correct_input_N(n);
	cout << "Enter the matrix A: \n";
	double ** original_matrix = matrix_input(n, n);
	double ** resoult_matrix = func_calc(original_matrix, n);
	clear_memory_after_matrix(original_matrix, n);
	clear_memory_after_matrix(resoult_matrix, n);
	return 0;
}
