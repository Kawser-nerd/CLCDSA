#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	int cases;
	scanf("%d", &cases);
	for (int T = 1; T <= cases; ++T) {
		printf("Case #%d: ", T);
		char board[4][5];
		for (int r = 0; r < 4; ++r)
			scanf("%s", board[r]);
		bool x_won = false, o_won = false;
		bool x_ok, o_ok;

		for (int r = 0; r < 4; ++r) {
			x_ok = true;
			o_ok = true;
			for (int c = 0; c < 4; ++c) {
				int m = board[r][c];
				x_ok &= m == 'X' || m == 'T';
				o_ok &= m == 'O' || m == 'T';
			}
			x_won |= x_ok;
			o_won |= o_ok;
		}

		for (int c = 0; c < 4; ++c) {
			x_ok = true;
			o_ok = true;
			for (int r = 0; r < 4; ++r) {
				int m = board[r][c];
				x_ok &= m == 'X' || m == 'T';
				o_ok &= m == 'O' || m == 'T';
			}
			x_won |= x_ok;
			o_won |= o_ok;
		}

		x_ok = true;
		o_ok = true;
		for (int i = 0; i < 4; ++i) {
			int m = board[i][i];
			x_ok &= m == 'X' || m == 'T';
			o_ok &= m == 'O' || m == 'T';
		}
		x_won |= x_ok;
		o_won |= o_ok;

		x_ok = true;
		o_ok = true;
		for (int i = 0; i < 4; ++i) {
			int m = board[i][3-i];
			x_ok &= m == 'X' || m == 'T';
			o_ok &= m == 'O' || m == 'T';
		}
		x_won |= x_ok;
		o_won |= o_ok;

		bool has_dot = memchr(board, '.', sizeof board) != NULL;

		if (x_won && o_won)
			puts("Draw");
		else if (x_won || o_won)
			puts(x_won ? "X won" : "O won");
		else if (has_dot)
			puts("Game has not completed");
		else
			puts("Draw");
	}
	return 0;
}
