#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define DEBUGF(s, ...) fprintf(stderr, "DEBUG #%d: " s, t+1, ##__VA_ARGS__)

void do_test(int t)
{
	char cake[100][100] = { 0 };
	int r, c;
	int i, j;
	int first_nonempty_row = -1;
	
	scanf("%d %d", &r, &c);

	for (i = 0; i < r; i++)
	{
		int empty = 1;
		for (j = 0; j < c; j++)
		{
			scanf(" %c", &cake[i][j]);
			if (empty && cake[i][j] != '?')
			{
				int jj;
	
				empty = 0;
				for (jj = 0; jj < j; jj++)
					cake[i][jj] = cake[i][j];
			}
			if (!empty && cake[i][j] == '?')
				cake[i][j] = cake[i][j-1];	
		}
		if (first_nonempty_row < 0 && !empty)
		{
			int ii;

			first_nonempty_row = r;
			for (ii = 0; ii < i; ii++)
				memcpy(&cake[ii], &cake[i], sizeof cake[i]);
		}
		if (first_nonempty_row >= 0 && empty)
			memcpy(&cake[i], &cake[i-1], sizeof cake[i]);
	}

	printf("Case #%d:\n", t + 1);
	for (i = 0; i < r; i++)
		puts(cake[i]);
}

int main()
{
	int t, i;

	scanf("%d", &t);
	
	for (i = 0; i < t; i++)
		do_test(i);

	return 0;
}
