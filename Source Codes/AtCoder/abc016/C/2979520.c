/*
AtCoder Beginner Contest 016 C - ?????
??:
*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

//#define DEBUG1
//#define DEBUG2
//#define DEBUGF

int main() {
	static int n, m, a, b;
	static int i, j, k, cnt, ans;
	static int f[10][10] = { 0 };

	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; i++) {
		scanf("%d %d", &a, &b);
		f[a - 1][b - 1] = 1;
		f[b - 1][a - 1] = 1;
	}

	for (i = 0; i < n; i++) {
		int cnt = 0;
		int ff[10] = { 0 };
		for (j = 0; j < n; j++) {
			if (f[i][j] != 0) {
				for (k = 0; k < n; k++) {
					if (i != k && !f[i][k] && f[j][k]) {
						ff[k]=1;
					}
				}
			}
		}
		for (j = 0; j<n; j++) {
			if (ff[j])cnt++;
		}
		printf("%d\n", cnt);
	}
#ifdef DEBUGF
		getch();
#endif
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &n, &m);
  ^
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &a, &b);
   ^