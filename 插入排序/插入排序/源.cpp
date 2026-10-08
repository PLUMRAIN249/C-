#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int a[5] = { 5, 3, 4, 1, 2 };
    int i, j, temp;

    for (i = 1; i < 5; i++)
    {
        temp = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = temp;
    }

    for (i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}