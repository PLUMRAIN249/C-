#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int a[6] = { 5, 2, 8, 1, 6, 3 };

    int i, j;
    int min;
    int temp;

    for (i = 0; i < 5; i++)
    {
        min = i;

        for (j = i + 1; j < 6; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }

    for (i = 0; i < 6; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}