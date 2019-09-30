#include <stdio.h>
#include <stdlib.h>

int gcd(long a,long b){
	long r,tmp;
	if(a<b){
    	tmp = a;
    	a = b;
    	b = tmp;
  	}
 
  /* ?????????? */
  r = a % b;
  while(r!=0){
    a = b;
    b = r;
    r = a % b;
  }
	return b;
}
int main(void){
	long N,X;
	long i,j;
	long x[100000];
	scanf("%ld %ld",&N,&X);
	for(i=0;i<N;i++){
		scanf("%ld",&x[i]);
		x[i] = labs(x[i]-X);
	}
	long ans = x[0];
	for(i=0;i<N-1;i++){
		ans = gcd(x[i],x[i+1]);
		x[i+1]=ans;
	}
	printf("%ld",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld %ld",&N,&X);
  ^
./Main.c:27:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld",&x[i]);
   ^