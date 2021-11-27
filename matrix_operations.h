#ifndef MATRIX_OPERATIONS
#define MATRIX_OPERATIONS
//�������� ������� �������
double** matrix_nul(int n);

//�������� ������ ����� �������� �������
void clear_memory_after_matrix(double** matr, int n);

//���� ��������� ������� � ����������
double** matrix_input(int n);

//����� �������
void matrix_output(double** matr, int n);

//������� �������� ������� � ������
double** matrix_addition_num(double** matr, int num, int n);

//������� ��������� ������� �� �����
double** matrix_multiply_num(double** matr, int num, int n);

//������� �������� ������
double** matrix_addition_matrix(double** matr_1, double** matr_2, int n);

//������� ������������ ������
double** matrix_multiply_matrix(double** matr_1, double** matr_2, int n);

//������ ������� f(x) = 3*x^3 + 5*x^2 + x - 2. ��� f(A^2)
double** function_calculation(double** orig_matr, int n);
#endif
