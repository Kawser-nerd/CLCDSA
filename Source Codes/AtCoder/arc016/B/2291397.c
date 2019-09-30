/*
AtCoder Regular Contest 016 B - ????? ??:
*/

#include<stdio.h>

//#define DEBUG1
//#define DEBUGF

int max(int a, int b) { return a >= b ? a : b; }

int main() {
	int n;
	char x[100][10];
	int ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
			scanf("%s", &x[i]);
	}
#ifdef DEBUG1
	printf("\n");
	for (int i = 0; i < n; i++) {
			printf("%s\n", &x[i]);
	}
#endif
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			if (x[i][j] == 'x') {
				ans++;
			}
			else if (x[i][j] == 'o'&& x[i-1][j] != 'o') {
				ans++;
			}
		}
	}

	/*??*/
	printf("%d", ans);
	printf("\n");
#ifdef DEBUG1
	for (int i = 1; i <= n; i++) {
		scanf("%f", &MT[i]);
		scanf("%f", &mt[i]);
	}
	for (int i = 1; i < 6; i++) {
		printf(" %d", ans[i]);
	}
#endif
#ifdef DEBUGF
	getch();
#endif
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:10: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[10]’ [-Wformat=]
    scanf("%s", &x[i]);
          ^
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:18:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%s", &x[i]);
    ^