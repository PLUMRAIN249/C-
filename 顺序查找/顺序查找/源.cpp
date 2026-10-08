#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int a[5] = { 10, 20, 30, 40, 50 };
    int key = 30;
    int i;
    int found = -1;

    for (i = 0; i < 5; i++)
    {
        if (a[i] == key)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
    {
        printf("没有找到\n");
    }
    else
    {
        printf("找到了，下标为%d\n", found);
    }

    return 0;
}