#ifndef MATRIX_OPERATIONS
#define MATRIX_OPERATIONS
//�������� ������� ���������� �������
double** sqr_matrix_nul_create(int n);

//�������� ������ ����� �������� �������
void matrix_memory_clear(double** matr, int n);

//���� ���������� �������
double** sqr_matrix_input(int n);

//����� ��������� ���������� �������
void sqr_matrix_output(double** orig_matr, int n);

//������� �������� ���������� ������� � ������
double** sqr_matrix_addition_num(double** matr, int n, int num);

//������� ��������� ���������� ������� �� �����
double** sqr_matrix_multiply_num(double** matr, int n, int num);

//������� �������� ���������� ������
double** sqr_matrix_addition_matrix(double** matr_1, double** matr_2, int n);

//������� ������������ ���������� ������
double** sqr_matrix_multiply_matrix(double** matr_1, double** matr_2, int n);

//������ ������� X = A^2
double** sqr_matrix_pow_2(double** orig_matr, int n);

//������ ������� f(x) = 3*x^3 + 5*x^2 + x - 2.
double** function_calculation(double** x_matr, int n);

//����������� ������� ��� ���������� ������������ �������.
int matrix_det(double** matr, int n);

//���������� ������� minor_matr ��� ���������� ������, ����� ������������� row-�� ������ � col-���� ������� ������� matr;
void matrix_for_minor(double **matr, int n, int row, int col, double **minor_matr);

//�������� ������� ������� ������ �������
double** matrix_nul_create(int n, int m);

//���� ������� ������ �������
double** matrix_input(int n, int m);

//����� ������� ������ �������
void matrix_output(double** orig_matr, int n, int m);

//������� ��������� ������� ������ ������� �� �����
double** matrix_multiply_num(double** matr, int n, int m, int num);

//������� �������� ������ ������ �������
double** matrix_addition_matrix(double** matr_1, double** matr_2, int n, int m);

//������� ������������ ������
double** matrix_multiply_matrix(double** matr_1, int n1, int m1, double** matr_2, int n2, int m2);

//���������� �������� �-��
double** matrix_inverse(double** matr, int n);

//������� ������� ������
void matrix_system_solution(double** &matr_A, double** &matr_B, double** matr_C1, double** matr_C2, int n, int m);
#endif
