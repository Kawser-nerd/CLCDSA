#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);
	char S[N][N+1];
	int i, j;
	for (i = 0; i < N; i++) {
		scanf("%s", &S[i]);
	}
	int red=0, blue=0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (S[i][j] == 'B') {
				blue += 1;
			} else if (S[i][j] == 'R') {
				red += 1;
			}
		}
	}
	if (red > blue) {
		printf("TAKAHASHI\n");
	} else if (red < blue) {
		printf("AOKI\n");
	} else {
		printf("DRAW\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:9: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[(sizetype)(N + 1)]’ [-Wformat=]
   scanf("%s", &S[i]);
         ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", &S[i]);
   ^