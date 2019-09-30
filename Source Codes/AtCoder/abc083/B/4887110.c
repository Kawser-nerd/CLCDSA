#include<stdio.h>

int main(void) {
	int i,N,n,A,B,sum,Asum=0;
	scanf("%d %d %d",&N,&A,&B);
	for(i=1;i<=N;i++) {
		sum=0;
		n = i;
		while(n) {
			sum += n%10;
			n/=10;
		}
		if(sum>=A && sum<=B) {
			Asum += i;
		}
	}
	printf("%d",Asum);
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&N,&A,&B);
  ^