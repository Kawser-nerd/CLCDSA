#include<stdio.h>

int tate[8] = {0}, yoko[8] = {0}, migisita[15] = {0}, migiue[15] = {0};
int end = 0;
char c[8][8];

void check()
{
	int i, j;

	for(i = 0; i < 8; i++)
		for(j = 0; j < 8; j++)
			if(c[i][j] == 'Q')
			{
				tate[j]++;
				yoko[i]++;
				migisita[i - j + 7]++;
				migiue[i + j]++;
			}

	for(i = 0; i < 8; i++)
		if(tate[i] > 1 || yoko[i] > 1)
			end = 1;

	for(i = 0; i < 15; i++)
		if(migisita[i] > 1 || migiue[i] > 1)
			end = 1;
}

void putting(int num)
{
	int i, j, m, n;

	for(i = 0; i < 8; i++)
		for(j = 0; j < 8; j++)
			if(tate[j]  == 0 && yoko[i] == 0 && migisita[i - j + 7] == 0 && migiue[i + j] == 0)
			{
				c[i][j] = 'Q';

				tate[j]++;
				yoko[i]++;
				migisita[i - j + 7]++;
				migiue[i + j]++;

				if(num == 7)
				{
					for(m = 0; m < 8; m++)
					{
						for(n = 0; n < 8; n++)
							putchar(c[m][n]);

						putchar('\n');
					}

					end = 1;
				}

				else
				{
					putting(num + 1);

					c[i][j] = '.';

					tate[j]--;
					yoko[i]--;
					migisita[i - j + 7]--;
					migiue[i + j]--;
				}
			}
}

int main()
{
	int i, j;

	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 8; j++)
			c[i][j] = getchar();

		while(getchar() != '\n')
			;
	}

	check();

	if(end)
	{
		puts("No Answer");

		return 0;
	}

	putting(3);

	if(!end)
		puts("No Answer");

	return 0;
}