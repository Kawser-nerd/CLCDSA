#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	long long N, x;
	long long a[100000];
	scanf("%lld %lld", &N, &x);
	int i;
	for(i = 0; i < N; i++) {
		scanf("%lld", &a[i]);
	}
	long long count = 0;
	
	for ( i = 0; i < (N - 1); i++) {
		if ( (a[i] + a[i+1]) <= x )
			continue;
		else if (x <= a[i]) {
			count += a[i+1];
			count += a[i] - x;
			a[i] = x;
			a[i+1] = 0;
		} else {
			count += (a[i] + a[i+1] - x);
			a[i+1] = x - a[i]; 
		}
	}
	printf("%lld", count);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld", &N, &x);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &a[i]);
   ^