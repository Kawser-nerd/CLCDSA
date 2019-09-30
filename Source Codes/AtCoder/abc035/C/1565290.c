#include<stdio.h>
int main(void)
{
	int n,q,a,b,x[200001],s[200001],sum,i;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) x[i]=0;
	for(i=0;i<q;i++){
		scanf("%d%d",&a,&b);
		x[a]++; x[b+1]--;
	}
	sum=0;
	for(i=1;i<=n;i++){
		sum+=x[i];
		if(sum%2==1) s[i]=1;
		else s[i]=0;
	}
	for(i=1;i<=n;i++) printf("%d",s[i]);
	printf("\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&q);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^