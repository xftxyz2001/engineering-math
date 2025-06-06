/* ���ҳ������� */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIMS 1000000

int main()
{
    const double pA = 0.80;    // �׳������ P(A)
    const double pB_A = 0.20;  // �׳���ʱ�ҳ��� P(B|A)
    const double pB_nA = 0.90; // �ײ�����ʱ�ҳ��� P(B|?A)

    // (1) ȫ���ʹ�ʽ
    double pB = pB_A * pA + pB_nA * (1 - pA);
    printf("���� P(B) = %.4f\n", pB);

    // (2) ��Ҷ˹��ʽ
    double pA_B = pB_A * pA / pB;
    printf("���� P(A|B) = %.4f\n", pA_B);

    // Monte?Carlo ��֤
    long cntA = 0, cntB = 0, cntAB = 0;
    srand((unsigned)time(NULL));
    for (long i = 0; i < SIMS; ++i)
    {
        int A = (rand() < pA * RAND_MAX);
        int B;
        if (A)
            B = (rand() < pB_A * RAND_MAX);
        else
            B = (rand() < pB_nA * RAND_MAX);

        if (A)
            cntA++;
        if (B)
            cntB++;
        if (A && B)
            cntAB++;
    }
    printf("����  P(B) = %.4f\n", (double)cntB / SIMS);
    printf("����  P(A|B) = %.4f\n", (double)cntAB / cntB);
    return 0;
}