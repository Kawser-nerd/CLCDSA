#include <stdbool.h>
#include <stdio.h>

int main(void)
{
	int cases;
	scanf("%d", &cases);
	for (int T = 1; T <= cases; ++T) {
		int R, C;
		scanf("%d %d", &R, &C);
		int field[110][110];
		int row_max[110] = {}, col_max[110] = {};
		for (int r = 0; r < R; ++r) {
			for (int c = 0; c < C; ++c) {
				int h;
				scanf("%d", &h);
				field[r][c] = h;
				if (h > row_max[r])
					row_max[r] = h;
				if (h > col_max[c])
					col_max[c] = h;
			}
		}

		bool field_ok = true;
		for (int r = 0; field_ok && r < R; ++r) {
			for (int c = 0; field_ok && c < C; ++c) {
				int h = row_max[r];
				if (col_max[c] < h)
					h = col_max[c];
				if (field[r][c] != h)
					field_ok = false;
			}
		}

		printf("Case #%d: %s\n", T, field_ok ? "YES" : "NO");
	}
	return 0;
}
