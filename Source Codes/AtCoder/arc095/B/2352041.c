#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	int n, i;
	int a[100000] = {0}, max = 0;
	int k = 0;
	
	scanf("%d", &n);
	for(i=0;i<n;++i){
		scanf("%d", a+i);
		a[i] = a[i] * 2;
		if( a[i] > max ) max = a[i];
	}
	for(i=0; i<n; ++i){
		int d1, d2;
		d1 = (max/2) < k ? (k-max/2) : (max/2-k);
		d2 = (max/2) < a[i] ? (a[i] - max/2) : (max/2 - a[i]);
		if( d2 < d1 ) k = a[i];
	}
	
	printf("%d %d\n", max/2, k/2);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", a+i);
   ^