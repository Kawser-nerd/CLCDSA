#include <stdio.h>

char color_str[6] = {'R', 'O', 'Y', 'G', 'B', 'V'};

int main(void)
{
	int i, T;
	scanf("%d", &T);
	for (i = 0; i < T; ++i) {
		int N, j, l, k;
		int color[6];
		char ans[1000] = {0, };
		int top, mid, bot;

		scanf("%d", &N);
		for (j = 0; j < 6; ++j) {
			scanf("%d", &color[j]);
		}

		top = 0;
		if (color[top] < color[2]) {
			mid = top;
			top = 2;
		}
		else 
			mid = 2;

		if (color[top] < color[4]) {
			bot = mid;
			mid = top;
			top = 4;
		}
		else {
			if (color[mid] < color[4]) {
				bot = mid;
				mid = 4;
			}
			else {
				bot = 4;
			}
		}
		
		if (color[mid] + color[bot] < color[top]) {
			printf("Case #%d: IMPOSSIBLE\n", i + 1);
		}
		else {
			l = 0;
			for (j = 0; j < color[top]; ++j) {
				ans[l] = color_str[top];
				l += 2;
			}
			l = N - 1;
			for (j = 0; j < color[mid]; ++j) {
				ans[l] = color_str[mid];
				l -= 2;
				if (ans[l] != 0)
					l--;
			}
			for (j = 0; j < N; ++j) {
				if (ans[j] == 0)
					ans[j] = color_str[bot];
			}
			printf("Case #%d: ", i + 1);
			for (j = 0; j < N; ++j)
				printf("%c", ans[j]);
			printf("\n");
		}
	}
}
