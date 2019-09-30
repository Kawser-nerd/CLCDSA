#include<stdio.h>

int main(){
	long long n;
	scanf("%lld",&n);
	n=n%30;
	int ans[6],i,j;
	for(i=1;i<=6;i++)ans[i-1]=i;
	for(j=0;j<n;j++){
		int tmp=ans[j%5];
		ans[j%5]=ans[j%5+1];
		ans[j%5+1]=tmp;
	}
	for(i=0;i<6;i++)printf("%d",ans[i]);
	puts("");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^