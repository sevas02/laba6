#ifndef MATRIX_OPERATIONS
#define MATRIX_OPERATIONS
//создание нулевой матрицы
double** matrix_nul(int n);

//отчистка памяти после создания матрицы
void clear_memory_after_matrix(double** matr, int n);

//ввод начальной матрицы с клавиатуры
double** matrix_input(int n);

//вывод матрицы
void matrix_output(double** matr, int n);

//функция сложения матрицы с числом
double** matrix_addition_num(double** matr, int num, int n);

//функция умножения матрицы на число
double** matrix_multiply_num(double** matr, int num, int n);

//функция сложения матриц
double** matrix_addition_matrix(double** matr_1, double** matr_2, int n);

//функция перемножения матриц
double** matrix_multiply_matrix(double** matr_1, double** matr_2, int n);

//расчёт функции f(x) = 3*x^3 + 5*x^2 + x - 2. при f(A^2)
double** function_calculation(double** orig_matr, int n);
#endif
