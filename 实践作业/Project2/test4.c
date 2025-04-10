#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ����ת�ú���
void transposeMatrix(int **matrix, int **transpose, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }
}

// ��ӡ������
void printMatrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int rows, cols;
    printf("��������������: ");
    scanf("%d", &rows);
    printf("��������������: ");
    scanf("%d", &cols);

    // ��̬�����ڴ�
    int **matrix = (int **)malloc(rows * sizeof(int *));
    int **transpose = (int **)malloc(cols * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    for (int i = 0; i < cols; i++)
    {
        transpose[i] = (int *)malloc(rows * sizeof(int));
    }

    // �����������
    srand(time(NULL));
    printf("ԭʼ����:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = rand() % 10; // �������0��9֮��
        }
    }
    printMatrix(matrix, rows, cols); // ���ô�ӡ������

    // ת�þ���
    transposeMatrix(matrix, transpose, rows, cols);

    // ��ӡת�ú�ľ���
    printf("ת�ú�ľ���:\n");
    printMatrix(transpose, cols, rows); // ���ô�ӡ������

    // �ͷŷ�����ڴ�
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    for (int i = 0; i < cols; i++)
    {
        free(transpose[i]);
    }
    free(transpose);

    return 0;
}