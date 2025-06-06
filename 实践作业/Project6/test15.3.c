/* ��֢�ղ�ɿ��� */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIMS 1000000

int main()
{
    const double pC = 0.005;     // ���� P(C)
    const double pPos_C = 0.95;  // ������ = 1 - ������
    const double pPos_nC = 0.05; // ������

    // Bayes �������Ժ�Ļ������� (PPV)
    double pPos = pPos_C * pC + pPos_nC * (1 - pC);
    double pC_Pos = pPos_C * pC / pPos;
    printf("����  P(C|����) = %.4f\n", pC_Pos);

    // Monte?Carlo
    long cntC = 0, cntPos = 0, cntPosC = 0;
    srand((unsigned)time(NULL));
    for (long i = 0; i < SIMS; ++i)
    {
        int C = rand() < pC * RAND_MAX; // �Ƿ��滼��
        int Pos;
        if (C)
            Pos = rand() < pPos_C * RAND_MAX;
        else
            Pos = rand() < pPos_nC * RAND_MAX;

        if (C)
            cntC++;
        if (Pos)
            cntPos++;
        if (Pos && C)
            cntPosC++;
    }
    printf("����  P(C|����) = %.4f\n", (double)cntPosC / cntPos);

    if (pC_Pos < 0.5)
        printf("����: ����Ԥ��ֵ�� %.2f%%, �������ڴ��ģ�ղ顣\n", pC_Pos * 100);
    else
        printf("����: �ɿ��������ղ顣\n");
    return 0;
}