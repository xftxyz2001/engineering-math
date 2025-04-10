#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ��������
void inputMatrix(int matrix[3][3]);
int sumDiagonal(int matrix[3][3]);
void multiplyMatrices(int A[3][3], int B[3][3], int result[3][3]);
void printMatrix(int matrix[3][3]);
int main(int argc, char const *argv[])
{

    int matrix1[3][3];
    int matrix2[3][3];
    int result[3][3] = {0};

    printf("�������һ��3x3����:\n");
    inputMatrix(matrix1);

    printf("������ڶ���3x3����:\n");
    inputMatrix(matrix2);

    // �����һ������ĶԽ���Ԫ��֮��
    int diagonalSum = sumDiagonal(matrix1);
    printf("��һ������ĶԽ���Ԫ��֮��: %d\n", diagonalSum);

    // �������Ƿ�������
    if (sizeof(matrix1[0]) / sizeof(matrix1[0][0]) == sizeof(matrix2) / sizeof(matrix2[0]))
    {
        multiplyMatrices(matrix1, matrix2, result);
        printf("������˽��:\n");
        printMatrix(result);
    }
    else
    {
        printf("�����޷���ˣ���Ϊ��һ����������������ڵڶ��������������\n");
    }

    return 0;
}

// ����һ��3x3����
void inputMatrix(int matrix[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("�����%d�е�%d�е�Ԫ��: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// ����3x3����Խ���Ԫ��֮��
int sumDiagonal(int matrix[3][3])
{
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += matrix[i][i];
    }
    return sum;
}

// �������
void multiplyMatrices(int A[3][3], int B[3][3], int result[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// ��ӡ����
void printMatrix(int matrix[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
