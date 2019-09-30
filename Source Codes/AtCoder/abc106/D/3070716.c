#include <stdio.h>

#define NMAX 501

int N, M, Q;
int l, r, p, q;
int lr[NMAX][NMAX], s[NMAX][NMAX];

int main()
{
	int i, j;
	int sum;
	
	for(i = 0; i <= N; i++) {
		for(j = 0; j <= N; j++) {
			lr[i][j] = 0;
			s[i][j] = 0;
		}
	}
	
	scanf("%d %d %d", &N, &M, &Q);
	for(i = 0; i < M; i++) {
		scanf("%d %d", &l, &r);
		lr[l][r]++;
	}
	
	for(i = 1; i <= N ; i++) {
		for(j = 1; j <= N; j++) {
			s[i][j] = s[i][j-1] + lr[i][j];
		}
	}
	
	for(i = 0; i < Q; i++) {
		scanf("%d %d", &p, &q);
		sum = 0;
		for(j = p; j <= q; j++) {
			sum += s[j][q] - s[j][p-1];
		}
		printf("%d\n", sum);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d", &N, &M, &Q);
  ^
./Main.c:23:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &l, &r);
   ^
./Main.c:34:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &p, &q);
   ^