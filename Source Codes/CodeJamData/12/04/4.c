#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

#define MAXH 100
#define MAXW 100

char board[MAXH][MAXW];

int reflect_updown(int start_r, int start_c, int d, int dir)
{
	int pos_row = start_r;

	do {
		pos_row += dir;
		d -= 1;

		if (pos_row == start_r)
			return 1;

		if (pos_row % 2 == 0 && board[dir > 0 ? pos_row / 2 : pos_row / 2 - 1][start_c / 2] == '#')
			dir = -dir;
	} while (d > 0);

	return 0;
}

int reflect_leftright(int start_r, int start_c, int d, int dir)
{
	int pos_col = start_c;

	do {
		pos_col += dir;
		d -= 1;

		if (pos_col == start_c)
			return 1;

		if (pos_col % 2 == 0 && board[start_r / 2][dir > 0 ? pos_col / 2 : pos_col / 2 - 1] == '#')
			dir = -dir;
	} while (d > 0);

	return 0;
}
	
int reflect_straight(int start_r, int start_c, int d)
{
	return reflect_updown(start_r, start_c, d, 1) +
		reflect_updown(start_r, start_c, d, -1) +
		reflect_leftright(start_r, start_c, d, 1) +
		reflect_leftright(start_r, start_c, d, -1);
}

int reflect(int start_r, int start_c, int a, int b, int d, int dir_row, int dir_col)
{
	int pos_row = start_r;
	int pos_col = start_c;
	int toedge_row = a;
	int toedge_col = b;
	int n_exact = 0;

	//fprintf(stderr, "Starting at (%d, %d) heading (%cve, %cve)\n", pos_row, pos_col, dir_row > 0 ? '+' : '-', dir_col > 0 ? '+' : '-');

	do {
		if (toedge_row > toedge_col)
		{
			toedge_row -= toedge_col;
			toedge_col = b;

			pos_col += dir_col;
			//fprintf(stderr, "Intersecting column %d between row %d and %d\n", pos_col, pos_row, pos_row + dir_row);

			if (pos_col % 2 == 0 && board[min(pos_row, pos_row + dir_row) / 2][dir_col > 0 ? pos_col / 2 : pos_col / 2 - 1] == '#')
			{
				dir_col = -dir_col;
				//fprintf(stderr, "\t->reflecting, heading (%cve, %cve)\n", dir_row > 0 ? '+' : '-', dir_col > 0 ? '+' : '-');
			}
		}
		else if (toedge_col > toedge_row)
		{
			toedge_col -= toedge_row;
			toedge_row = a;

			pos_row += dir_row;
			//fprintf(stderr, "Intersecting row %d between col %d and %d\n", pos_row, pos_col, pos_col + dir_col);

			if (pos_row % 2 == 0 && board[dir_row > 0 ? pos_row / 2 : pos_row / 2 - 1][min(pos_col, pos_col + dir_col) / 2] == '#')
			{
				dir_row = -dir_row;
				//fprintf(stderr, "\t->reflecting, heading (%cve, %cve)\n", dir_row > 0 ? '+' : '-', dir_col > 0 ? '+' : '-');
			}
		}
		else
		{
			toedge_row = a;
			toedge_col = b;

			pos_col += dir_col;
			pos_row += dir_row;
			n_exact++;
			//fprintf(stderr, "Reached exact point (%d, %d)\n", pos_row, pos_col);

			if (n_exact * n_exact * (a * a + b * b) > d * d)
			{
				//fprintf(stderr, "\t->too far, stopping.\n");
				break;
			}

			if (pos_row == start_r && pos_col == start_c)
			{
				//fprintf(stderr, "\t->reached target! stopping.\n");
				return 1;
			}

			if (pos_row % 2 == 1 && pos_col % 2 == 0 && board[pos_row / 2][dir_col > 0 ? pos_col / 2 : pos_col / 2 - 1] == '#')
			{
				dir_col = -dir_col;
				//fprintf(stderr, "\t->(off main grid) reflecting off col, heading (%cve, %cve)\n", dir_row > 0 ? '+' : '-', dir_col > 0 ? '+' : '-');
			}
			else if (pos_row % 2 == 0 && pos_col % 2 == 1 && board[dir_row > 0 ? pos_row / 2 : pos_row / 2 - 1][pos_col / 2] == '#')
			{
				dir_row = -dir_row;
				//fprintf(stderr, "\t->(off main grid) reflecting off row, heading (%cve, %cve)\n", dir_row > 0 ? '+' : '-', dir_col > 0 ? '+' : '-');
			}
			else if (pos_row % 2 == 0 && pos_col % 2 == 0 && board[dir_row > 0 ? pos_row / 2 : pos_row / 2 - 1][dir_col > 0 ? pos_col / 2 : pos_col / 2 - 1] == '#')
			{
				int reflect_col = 0, reflect_row = 0;

				if (board[dir_row > 0 ? pos_row / 2 - 1: pos_row / 2][dir_col > 0 ? pos_col / 2 : pos_col / 2 - 1] == '#')
				{
					//fprintf(stderr, "\t->reflecting off col\n");
					reflect_col = 1;
				}
				if (board[dir_row > 0 ? pos_row / 2 : pos_row / 2 - 1][dir_col > 0 ? pos_col / 2 - 1 : pos_col / 2] == '#')
				{
					//fprintf(stderr, "\t->reflecting off row\n");
					reflect_row = 1;
				}

				if (reflect_col)
					dir_col = -dir_col;
				if (reflect_row)
					dir_row = -dir_row;

				if (!reflect_col && !reflect_row)
				{
					//fprintf(stderr, "\t->absorbed by corner, stopping.\n");
					break;
				}
			}	
		}
	} while (1);

	return 0;
}

/* Perform reflection in all quadrants for given a:b */
int reflect_all_quads(int start_r, int start_c, int a, int b, int d)
{
	return reflect(start_r, start_c, a, b, d, 1, 1) +
		reflect(start_r, start_c, a, b, d, 1, -1) +
		reflect(start_r, start_c, a, b, d, -1, 1) +
		reflect(start_r, start_c, a, b, d, -1, -1);
}

/* greatest common divisor */
int gcd(int a, int b)
{
	if (b == 0)
		return a;

	return gcd(b, a % b);
}

/* Perform reflection for all ratios */
int reflect_all_ratios(int start_r, int start_c, int d)
{
	int a, b;
	int total = reflect_all_quads(start_r, start_c, 1, 1, d);

	for (a = 1; a < d; a++)
		for (b = a + 1; b * b <= d * d - a * a; b++)
			if (gcd(a, b) == 1)
			{
				total += reflect_all_quads(start_r, start_c, a, b, d);
				total += reflect_all_quads(start_r, start_c, b, a, d);
			}

	return total;
}	

int reflect_all(int start_r, int start_c, int d)
{
	return reflect_straight(start_r, start_c, d) +
		reflect_all_ratios(start_r, start_c, d);
}

void do_test(int t)
{
	int h, w, d, c;
	int i, j;
	int start_r, start_c;

	scanf("%d %d %d", &h, &w, &d);

	while (c = getchar(), c != EOF && c != '\n')
		;

	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			board[i][j] = getchar();

			if (board[i][j] == 'X')
			{
				start_r = i * 2 + 1;
				start_c = j * 2 + 1;
			}
		}
		while (c = getchar(), c != EOF && c != '\n')
			;
	}

	printf("Case #%d: %d\n", t + 1, reflect_all(start_r, start_c, d * 2));
}

int main()
{
	int t, i;

	scanf("%d", &t);
	
	for (i = 0; i < t; i++)
		do_test(i);

	return 0;
}
