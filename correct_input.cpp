#include "correct_input.h"
#include <iostream>
using namespace std;

//корректный ввод натурального числа
void correct_input_N(int &num) {
	cin >> num;
	while (cin.fail() || num <= 0) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "¬ведите натуральное значение переменной!\n";
		cin >> num;
	}
}

//корректный ввод вещественного числа
void correct_input_R(double &num) {

	cin >> num;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "¬ведите натуральное значение переменной!\n";
		cin >> num;
	}
}