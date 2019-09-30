#include<stdio.h> 
int main()
{
	int n,a,b,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a,&b);
		ans+=(b-a)+1;
	}
	printf("%d",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^