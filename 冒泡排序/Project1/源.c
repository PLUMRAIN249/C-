#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a[6] = { 5,2,8,1,6,3 };
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5-i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp;
				temp = a[j];
				a[j] = a[j + 1];
				a[j+ 1] = temp;
			}
		}
	}
	for (i = 0; i < 6; i++)
	{
		printf("%d", a[i]);
	}
	return 0;
}