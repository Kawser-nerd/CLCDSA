#include <cstdio>
#include <cstdlib>
int T, R, C;
char input[55][55];
int fill() {
	int i, j;
	for (i = 0; i < R; i ++)
		for (j = 0; j < C; j ++)
			if (input[i][j] == '#') {
				if (i < R - 1 && j < C - 1 && input[i][j + 1] == '#' && input[i + 1][j] == '#' && input[i + 1][j + 1] == '#') {
					input[i][j] = input[i + 1][j + 1] = '/';
					input[i + 1][j] = input[i][j + 1] = '\\';
				}
				else
					return 0;
			}
	return 1;
}
int main() {
	int i, j, k, Case = 1;
	scanf("%d", &T);
	while (T --) {
		scanf("%d%d", &R, &C);
		for (i = 0; i < R; i ++)
			scanf("%s", input[i]);
		printf("Case #%d:\n", Case ++);
		if (fill()) {
			for (i = 0; i < R; i ++)
				printf("%s\n", input[i]);
		}
		else
			printf("Impossible\n");
	}
	return 0;
}
