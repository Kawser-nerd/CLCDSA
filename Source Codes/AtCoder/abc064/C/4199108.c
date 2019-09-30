#include<stdio.h>

int main(){
	int n,c[9]={0},i,a,ans=0,ansmax=0,ansmin=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a);
		if(a<3200)c[a/400]=1;
		else c[8]++;
	}
	for(i=0;i<8;i++)ans+=c[i];
		ansmin=ans;
		ansmax=ans+c[8];
	if(ans==0&&c[8]>=1)ansmin=1;
	printf("%d %d\n",ansmin,ansmax);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^