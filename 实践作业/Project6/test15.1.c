/* ��֤����Ƶ������ 1/2 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIMS 1000000 // ģ�����

int main()
{
    long boys = 0, girls = 0;
    srand((unsigned)time(NULL));
    for (long i = 0; i < SIMS; ++i)
    {
        if (rand() & 1)
            boys++; // ������λģ�� 0/1
        else
            girls++;
    }
    printf("ģ�����: %ld\n�к�: %ld (%.5f)\nŮ��: %ld (%.5f)\n",
           SIMS,
           boys, (double)boys / SIMS,
           girls, (double)girls / SIMS);
    return 0;
}