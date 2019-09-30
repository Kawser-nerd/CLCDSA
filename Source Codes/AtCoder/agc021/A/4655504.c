#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void){
	int ans,keta=0,c,i;
	long long N,n;
	scanf("%lld",&N);
	n=N;
	while(n>=1){n/=10;keta++;}
	c = N/(pow(10,keta-1));
	ans = c+9*(keta-1);
	n=0;
	for(i=keta-1;i>=0;i--){
		n*=10;
		if(i==keta-1) n += c;
		else n += 9;
	}
	if(n!=N)ans--;
	
	printf("%d",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&N);
  ^