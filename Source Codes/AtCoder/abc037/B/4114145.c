#include <stdio.h>
#include <stdlib.h>

int main(void){
	int n, q, l, r;
	long *a, t;
	scanf("%d %d", &n, &q);
	a = malloc(sizeof(long) * n);
	for(int i = 0; i < n; i++)
		a[i] = 0;
	for(int i = 0; i < q; i++){
		scanf("%d %d %ld", &l, &r, &t);
		for(int j = l - 1; j <= r - 1; j++)
			a[j] = t;
	}
	for(int i = 0; i < n; i++)
		printf("%ld\n", a[i]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &n, &q);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %ld", &l, &r, &t);
   ^