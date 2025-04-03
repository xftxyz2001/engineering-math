#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    // ����һ��3x3����
    double matrix[3][3];

    // ��ʾ�û��������Ԫ��
    printf("������һ��3x3�����Ԫ��:\n");
    printf("eg. \n2 5 8\n1 0 1\n1 3 2\n-----\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%lf", &matrix[i][j]);
        }
    }

    // ��������ʽ��ֵ
    double det = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) 
               - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) 
               + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);

    // �������ʽ��ֵ
    printf("�þ��������ʽ��ֵΪ: %lf\n", det);
    return 0;
}
