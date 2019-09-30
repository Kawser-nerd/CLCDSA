#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

#define lli long long int
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(a) ((a)<0?-(a):(a))




int main(void){
	lli n;
	int *p;
	lli *a,*b;

	lli bigint = 800000000;

	lli i;

	scanf("%lld",&n);
	//for(i=1;i<=20000;i++){
	//	printf("%d\n", i);
	//}

	p = calloc(sizeof(int),n);
	a = calloc(sizeof(lli),n);
	b = calloc(sizeof(lli),n);
	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
		p[i]--;
	}
	for(i=0;i<n;i++){
		a[i] = b[n-i-1] = i*50000 + 1;
	}
	for(i=0;i<n;i++){
		a[p[i]] += i+1;
	}
	for(i=0;i<n;i++){
		printf("%lld ", a[i]);
	}
	printf("\n");
	for(i=0;i<n;i++){
		printf("%lld ", b[i]);
	}
	printf("\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:33:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&p[i]);
   ^