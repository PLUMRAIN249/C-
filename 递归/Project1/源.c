#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int getMax(int a[], int n)
{
    if (n == 1)
        return a[0];

    int max = getMax(a, n - 1);

    if (a[n - 1] > max)
        max = a[n - 1];

    return max;
}

int main()
{
    int a[5] = { 3, 8, 2, 9, 5 };

    int max = getMax(a, 5);

    printf("最大值是：%d", max);

    return 0;
}