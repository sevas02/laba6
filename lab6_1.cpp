#include <iostream>
#include <iomanip>
#include "matrix_operations.h"
#include "correct_input.h"
using namespace std;

int main() {
	setlocale(0, "RUS");
	int n;
	cout << "hhhh";
	cout << "Ââåäèòå ðàçìåðíîñòü êâàäðàòíîé ìàòðèöû A: ";
	correct_input_N(n);
	cout << "Ââåäèòå ìàòðèöó A: \n";
	double ** original_matrix = matrix_input(n);
	double ** resoult_matrix = func_calc(original_matrix, n);
	clear_memory_after_matrix(original_matrix, n);
	clear_memory_after_matrix(resoult_matrix, n);
	return 0;
}
