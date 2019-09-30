#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define lli long long int
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define true 1
#define false 0



int main(void){
	int i;
	int n;
	lli t,a;
	lli mltt,mlta,mlt;
	lli anst,ansa;
	scanf("%d",&n);
	scanf("%lld%lld",&t,&a);
	anst = t;ansa = a;
	for(i=1;i<n;i++){
		scanf("%lld%lld",&t,&a);
		mlt = t < a ? anst / t : ansa / a;
		mltt = anst / t;
		if(anst % t)mltt++;
		mlta = ansa / a;
		if(ansa % a)mlta++;
		mlt = max(mltt,mlta);
		anst = t*mlt;ansa = a*mlt;
	}
	printf("%lld\n",anst + ansa );
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:20:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&t,&a);
  ^
./Main.c:23:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&t,&a);
   ^