#include <stdio.h>

main()
{
	int TC, T= 0;
	int R, C;
	int i, j, posible;
	char plano[60][60];
	scanf("%d", &TC);
	while (T++ < TC) {
		scanf("%d %d", &R, &C);
		for (i = 0; i < 60; i++)
			for (j = 0; j < 60; j++)
				plano[i][j] = 0;
		for (i = 0; i < R; i++)
			scanf("%s", plano[i]);
		posible = 1;
		for (i = 0; i < R; i++)
			for (j = 0; j < C; j++) {
				if (plano[i][j] == '#') {
					plano[i][j] = '/';
					if (plano[i+1][j] == '#' && plano[i][j+1] == '#' && plano[i+1][j+1] == '#') {
						plano[i+1][j] = '\\';
						plano[i+1][j+1] = '/';
						plano[i][j+1] = '\\';
					} else {
						posible = 0;
						break;
					}
				}
				if (posible == 0)
					break;
			}
			if (i == R && j == C) {
				printf("Case #%d:\n", T);
				for (i = 0; i < R; i++) {
					for (j = 0; j < C; j++)
						putchar(plano[i][j]);
					putchar('\n');
				}
			} else
				printf("Case #%d:\nImpossible\n", T);
	}
	return 0;
}

