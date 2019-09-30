#include<stdio.h>

int main(){
	long n,k;
	scanf("%ld%ld",&n,&k);
	//ans=k*(n-k+1)/((double)n*(double)n*(double)n);
	double ans1=((k-1)/(double)n)*(n-k)/((double)n*(double)n),
	ans2=(n-k)/((double)n*(double)n*(double)n),
	ans3=(k-1)/((double)n*(double)n*(double)n),
	ans4=1/((double)n*(double)n*(double)n);
	printf("%.20f\n",ans1*6+ans2*3+ans3*3+ans4);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld%ld",&n,&k);
  ^