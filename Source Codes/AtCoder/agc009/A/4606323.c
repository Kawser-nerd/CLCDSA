#include<stdio.h>

int main(){
	int n,i;
	long long ab[100000][2],ans=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%lld%lld",&ab[i][0],&ab[i][1]);
	for(i=n-1;i>=0;i--)ans+=(ab[i][1]-(ab[i][0]+ans)%ab[i][1])%ab[i][1];
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:7:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<n;i++)scanf("%lld%lld",&ab[i][0],&ab[i][1]);
                  ^