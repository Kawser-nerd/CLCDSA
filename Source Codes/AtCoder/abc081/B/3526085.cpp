#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

int main()
{
	int counter = 0,flag = 0;
	int a[200],n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	for(;;)
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i] % 2 == 0)
			{
				a[i] /= 2;
			}
			else
			{
				flag = 1;
			}
		}
		if (flag == 1) break;
		++counter;
	}

	printf("%d", counter);
}