#ifndef MATRIX_OPERATIONS
#define MATRIX_OPERATIONS
//создание нулевой квадратной матрицы
double** sqr_matrix_nul_create(int n);

//отчистка памяти после создания матрицы
void matrix_memory_clear(double** matr, int n);

//ввод квадратной матрицы
double** sqr_matrix_input(int n);

//вывод начальной квадратной матрицы
void sqr_matrix_output(double** orig_matr, int n);

//функция сложения квадратной матрицы с числом
double** sqr_matrix_addition_num(double** matr, int n, int num);

//функция умножения квадратной матрицы на число
double** sqr_matrix_multiply_num(double** matr, int n, int num);

//функция сложения квадратных матриц
double** sqr_matrix_addition_matrix(double** matr_1, double** matr_2, int n);

//функция перемножения квадратных матриц
double** sqr_matrix_multiply_matrix(double** matr_1, double** matr_2, int n);

//расчёт матрицы X = A^2
double** sqr_matrix_pow_2(double** orig_matr, int n);

//расчёт функции f(x) = 3*x^3 + 5*x^2 + x - 2.
double** function_calculation(double** x_matr, int n);

//Рекурсивная функция для нахождения определителя матрицы.
int matrix_det(double** matr, int n);

//Возвращает матрицу minor_matr для нахождения минора, путем вырчеркивания row-ой строки и col-того столбца матрицы matr;
void matrix_for_minor(double** matr, int n, int row, int col, double** minor_matr);

//создание нулевой матрицы любого размера
double** matrix_nul_create(int n, int m);

//ввод матрицы любого размера
double** matrix_input(int n, int m);

//вывод матрицы любого размера
void matrix_output(double** orig_matr, int n, int m);

//функция умножения матрицы любого размера на число
double** matrix_multiply_num(double** matr, int n, int m, int num);

//функция сложения матриц любого размера
double** matrix_addition_matrix(double** matr_1, double** matr_2, int n, int m);

//функция перемножения матриц
double** matrix_multiply_matrix(double** matr_1, int n1, int m1, double** matr_2, int n2, int m2);

//вычисление обратной м-цы
double** matrix_inverse(double** matr, int n);

//решение системы матриц
void matrix_system_solution(double**& matr_A, double**& matr_B, double** matr_C1, double** matr_C2, int n, int m);
#endif