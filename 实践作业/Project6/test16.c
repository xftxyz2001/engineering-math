/* coin_poisson.c ���� ����/���ɶԱ������ */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* ����׳� (k<=20) */
double fact(int k)
{
    static double memo[21] = {0};
    if (k == 0 || k == 1)
        return 1.0;
    if (memo[k])
        return memo[k];
    return memo[k] = k * fact(k - 1);
}

/* ����ϵ�� C(n,k) ʹ�� loggamma ����� */
long double comb(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;
    long double res = 1;
    for (int i = 1; i <= k; i++)
        res = res * (n - k + i) / i;
    return res;
}

int main()
{
    int n;
    double p;
    printf("������Ӳ�Ҵ��� n �� �ɹ����� p (�� 100 0.05): ");
    if (scanf("%d %lf", &n, &p) != 2)
        return 0;
    double lambda = n * p;
    printf("�� = np = %.4f\n", lambda);
    printf("k\tP_bin\t\tP_poi\t\trel_error(%%)\n");
    for (int k = 0; k <= 10; k++)
    {
        long double Pbin = comb(n, k) * pow(p, k) * pow(1 - p, n - k);
        long double Ppoi = pow(lambda, k) * exp(-lambda) / fact(k);
        long double err = fabsl(Pbin - Ppoi) / Pbin * 100;
        printf("%d\t%Le\t%Le\t%.3Lf\n", k, Pbin, Ppoi, err);
    }
    return 0;
}