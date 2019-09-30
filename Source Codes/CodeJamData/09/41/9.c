#include <stdio.h>

enum
{
	MAXN = 64
};

int N;
int rows[MAXN];

void input(void)
{
	int i, j;
	static char currentRow[MAXN];
	
	scanf("%d\n", &N);
	for(i = 0; i < N; i++)
	{
		gets(currentRow);
		rows[i] = 0;
		for(j = 0; currentRow[j]; j++)
		{
			if(currentRow[j] == '1')
			{
				rows[i] = j;
			}
		}
	}
}

int calc(void)
{
	int i, j, price, temp;
	static int pos[MAXN];
	
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			if(rows[j] <= i)
			{
				pos[j] = i;
				rows[j] = MAXN;
				break;
			}
		}
	}
	
	price = 0;
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			if(pos[j] == i)
			{
				break;
			}
		}
		for(; j > i; j--)
		{
			temp = pos[j];
			pos[j] = pos[j-1];
			pos[j-1] = temp;
			price++;
		}
	}
	
	return price;
}

int main(void)
{
	int T, test;
	
	scanf("%d\n", &T);
	for(test = 1; test <= T; test++)
	{
		input();
		printf("Case #%d: %d\n", test, calc());
	}
	
	return 0;
}
