#include <stdio.h>
#include <string.h>

#define N 30

int r, c;
char grid[N][N];

int is_blank_row(int i) {
	int j;
	
	for (j = 0; j < c; j++)
		if (grid[i][j] != '?')
			return 0;
	return 1;
}

void fill_row(int i) {
	int j, first_column;

	for (j = 0; j < c; j++)
		if (grid[i][j] != '?') {
			first_column = j;
			break;
		}

	for (j = first_column - 1; j >= 0; j--)
		if (grid[i][j] == '?')
			grid[i][j] = grid[i][j+1];

	for (j = first_column + 1; j < c; j++)
		if (grid[i][j] == '?')
			grid[i][j] = grid[i][j-1];
}

void solve(int case_no) {
	int i, first_row;

	scanf("%d%d", &r, &c);
	getchar();
	for (i = 0; i < r; i++)
		gets(grid[i]);

	for (i = 0; i < r; i++)
		if (!is_blank_row(i)) {
			first_row = i;
			break;
		}

	fill_row(first_row);

	for (i = first_row - 1; i >= 0; i--)
		if (is_blank_row(i))
			strcpy(grid[i], grid[i+1]);
		else
			fill_row(i);

	for (i = first_row + 1; i < r; i++)
		if (is_blank_row(i))
			strcpy(grid[i], grid[i-1]);
		else
			fill_row(i);

	printf("Case #%d:\n", case_no);
	for (i = 0; i < r; i++)
		puts(grid[i]);
}

int main(int argc, char** argv) {
	int case_no, t;

	scanf("%d", &t);
	for (case_no = 1; case_no <= t; case_no++)
		solve(case_no);

	return 0;
}