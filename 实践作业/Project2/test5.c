#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ��������
double determinant(double **matrix, int n);
double **minor(double **matrix, int n, int row, int col);
double **adjoint(double **matrix, int n);

int main()
{
    int n;
    printf("���������Ľ���: ");
    scanf("%d", &n);

    // ��̬��������ڴ�
    double **matrix = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; ++i)
    {
        matrix[i] = (double *)malloc(n * sizeof(double));
    }

    printf("����������Ԫ��:\n");
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%lf", &matrix[i][j]);
        }
    }

    double **adj = adjoint(matrix, n);

    printf("�������Ϊ:\n");
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%lf ", adj[i][j]);
        }
        printf("\n");
    }

    // �ͷ��ڴ�
    for (int i = 0; i < n; ++i)
    {
        free(matrix[i]);
        free(adj[i]);
    }
    free(matrix);
    free(adj);

    return 0;
}

// ��������ʽ
double determinant(double **matrix, int n)
{
    if (n == 1)
        return matrix[0][0];
    if (n == 2)
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    double det = 0;
    for (int i = 0; i < n; ++i)
    {
        double **m = minor(matrix, n, 0, i);
        det += pow(-1, i) * matrix[0][i] * determinant(m, n - 1);
        // �ͷ���ʽ���ڴ�
        for (int j = 0; j < n - 1; ++j)
        {
            free(m[j]);
        }
        free(m);
    }
    return det;
}

// �����������ʽ����
double **minor(double **matrix, int n, int row, int col)
{
    double **m = (double **)malloc((n - 1) * sizeof(double *));
    for (int i = 0; i < n - 1; ++i)
    {
        m[i] = (double *)malloc((n - 1) * sizeof(double));
    }

    int r = 0, c = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i == row)
            continue;
        c = 0;
        for (int j = 0; j < n; ++j)
        {
            if (j == col)
                continue;
            m[r][c] = matrix[i][j];
            ++c;
        }
        ++r;
    }
    return m;
}

// ����������
double **adjoint(double **matrix, int n)
{
    double **adj = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; ++i)
    {
        adj[i] = (double *)malloc(n * sizeof(double));
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            double **m = minor(matrix, n, i, j);
            adj[j][i] = pow(-1, i + j) * determinant(m, n - 1);
            // �ͷ���ʽ���ڴ�
            for (int k = 0; k < n - 1; ++k)
            {
                free(m[k]);
            }
            free(m);
        }
    }
    return adj;
}