#include <stdio.h>
#include <stdlib.h>

#define N 200000

int main(void){
	int a[N], b[N];
	int i, j, n;

	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}

	for(i=0; i*2<n; i++){
		b[i] = a[n-1-i*2];
	}
	for(i=0; i*2<n-1; i++){
		b[n-1-i] = a[n-2-i*2];
	}

	for(i=0; i<n; i++){
		printf("%d ", b[i]);
	}
	printf("\n");


	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a[i]);
   ^