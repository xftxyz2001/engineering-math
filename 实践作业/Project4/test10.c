#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 4

// �����������
void createMatrix(double matrix[][N], int n);

// ���
void printMatrix(double matrix[][N], int n);

// ��������
void swapRows(double matrix[][2 * N], int row1, int row2, int n);

// ��˹��Ԫ���������
void gaussJordanElimination(double matrix[][2 * N], int n);

int main()
{
    double A[N][N];
    createMatrix(A, N);
    printf("ԭʼ����:\n");
    printMatrix(A, N);

    // ������λ����
    double I[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            I[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }

    // �������뵥λ����ϲ�Ϊ�������
    double augmented[N][2 * N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            augmented[i][j] = A[i][j];
        }
        for (int j = N; j < 2 * N; j++)
        {
            augmented[i][j] = I[i][j - N];
        }
    }

    // ʹ�ø�˹��Ԫ���Ծ��������Ԫ
    gaussJordanElimination(augmented, N);

    // ��ȡ����󲿷�
    double inverse[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            inverse[i][j] = augmented[i][N + j];
        }
    }

    printf("�����:\n");
    printMatrix(inverse, N);

    return 0;
}

// ������ɾ���Ԫ��
void createMatrix(double matrix[][N], int n)
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = (double)(rand() % 1000) / 100.0;
        }
    }
}

// ���
void printMatrix(double matrix[][N], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%8.4f ", matrix[i][j]);
        }
        printf("\n");
    }
}

// ���������е�����
void swapRows(double matrix[][2 * N], int row1, int row2, int n)
{
    for (int j = 0; j < 2 * N; j++)
    {
        double temp = matrix[row1][j];
        matrix[row1][j] = matrix[row2][j];
        matrix[row2][j] = temp;
    }
}

// ��˹��Ԫ��
void gaussJordanElimination(double matrix[][2 * N], int n)
{
    for (int col = 0; col < n; col++)
    {
        // Ѱ����Ԫ���ڵ��У�ѡ�����ֵ�������Լ������
        int pivotRow = col;
        double maxVal = fabs(matrix[col][col]);
        for (int i = col + 1; i < n; i++)
        {
            if (fabs(matrix[i][col]) > maxVal)
            {
                maxVal = fabs(matrix[i][col]);
                pivotRow = i;
            }
        }

        // �����Ԫ�����в��ڵ�ǰ�У��򽻻���
        if (pivotRow != col)
        {
            swapRows(matrix, pivotRow, col, n);
        }

        // �������Ƿ����죨�����棩
        if (fabs(matrix[col][col]) < 1e-12)
        {
            printf("����������ģ��޷����档\n");
            exit(EXIT_FAILURE);
        }

        // ��һ����Ԫ��
        double pivot = matrix[col][col];
        for (int j = 0; j < 2 * N; j++)
        {
            matrix[col][j] /= pivot;
        }

        // ��ȥ������
        for (int i = 0; i < n; i++)
        {
            if (i != col)
            {
                double factor = matrix[i][col];
                for (int j = 0; j < 2 * N; j++)
                {
                    matrix[i][j] -= factor * matrix[col][j];
                }
            }
        }
    }
}