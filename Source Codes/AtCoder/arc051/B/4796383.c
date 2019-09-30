#include<stdio.h>

int main(){
	int n,i;
	long long num[50]={1,1};
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		num[i+1]=num[i]+num[i-1];
	}
	printf("%lld %lld",num[n-1],num[n]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^