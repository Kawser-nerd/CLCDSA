#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
	long long int n, m, i, j;
	scanf("%lld", &n);
	scanf("%lld", &m);
	if(n==1 && m==1){
		printf("%lld\n", n*m);
	}
	else if(n==1 || m==1){
		printf("%lld\n", n*m-2);
	}
	else {
		printf("%lld\n", (n-2)*(m-2));
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &n);
  ^
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &m);
  ^