#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int a[7] = { 10, 20, 30, 40, 50, 60, 70 };

    int key = 60;
    int left = 0;
    int right = 6;
    int found = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (a[mid] == key)
        {
            found = mid;
            break;
        }
        else if (a[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
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