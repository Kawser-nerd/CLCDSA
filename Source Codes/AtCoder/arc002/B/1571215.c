#include<stdio.h>

int check(int y, int m, int d)
{
	if(y % m == 0 && (y / m) % d == 0)
		return 1;
	else
		return 0;
}

void advance(int *a, int *b, int *c)
{
	int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if(*a % 4 == 0 && (*a % 100 != 0 || *a % 400 == 0))
		month[1]++;

	if(*b == 12 && *c == month[11])
	{
		(*a)++;
		*b = 1;
		*c = 1;
	}
	else if(*c == month[*b - 1])
	{
		(*b)++;
		*c = 1;
	}
	else
		(*c)++;
}

int main()
{
	int y, m, d;

	scanf("%d/%d/%d", &y, &m, &d);

	while(1)
	{
		if(check(y, m, d))
		{
			printf("%d/%02d/%02d\n", y, m, d);
			break;
		}
		else
			advance(&y, &m, &d);
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:37:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d/%d/%d", &y, &m, &d);
  ^