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

	j = 0;
	for(i=n-1; i>=0; i=i-2){
		b[j++] = a[i];
	}
	j=n-1;
	for(i=n-2; i>=0; i=i-2){
		b[j--] = a[i];
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