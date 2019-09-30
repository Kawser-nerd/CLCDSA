#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <regex.h>

#define lli long long int
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(a) ((a)<0?-(a):(a))
#define alloc(type,size) calloc(sizeof(type),size)

#define N 100001

int n,x;
int a[N];
lli res;
lli sum;


int main(void){
	int i;
	int mem;
	scanf("%d%d",&n,&x);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		sum += a[i];
	}
	if(a[0]>x) a[0] = x;
	res += a[0];
	for(i=1;i<n;i++){
		mem = x - (a[i] + a[i-1]);
		if(mem < 0) a[i] += mem;
		res += a[i];
	}
	printf("%lld\n", sum-res);
	
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:26:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&x);
  ^
./Main.c:28:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);
   ^