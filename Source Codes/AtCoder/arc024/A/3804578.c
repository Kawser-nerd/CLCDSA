#include <stdio.h>

int main()
{
	int L, R;
	scanf("%d%d", &L, &R);
	int l[L], r[R];
	int pair=0;
	int i, j;
	for (i = 0; i < L ; i++) {
		scanf("%d", &l[i]);
	}
	for (j = 0; j < R; j++) {
		scanf("%d", &r[j]);
	}
	for (i = 0; i < L; i++) {
		for (j = 0; j < R; j++) {
			if (l[i] == r[j]) {
				pair++;
				l[i] = 100;
				r[j] = 0;
			}
		}
	}
	printf("%d\n", pair);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &L, &R);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &l[i]);
   ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &r[j]);
   ^