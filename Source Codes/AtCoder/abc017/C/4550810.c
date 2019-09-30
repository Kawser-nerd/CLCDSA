#include<stdio.h>

#define N 100000
#define M 100002

int main(){
	int n,m,i,lrs[N][3];
	long long sum=0,ans=0,imos[M]={0};
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)scanf("%d%d%d",&lrs[i][0],&lrs[i][1],&lrs[i][2]);
	for(i=0;i<n;i++)sum+=lrs[i][2];
	for(i=0;i<n;i++){
		imos[lrs[i][0]]+=lrs[i][2];
		imos[lrs[i][1]+1]-=lrs[i][2];
	}
	for(i=1;i<M;i++)imos[i]+=imos[i-1];
	for(i=1;i<=m;i++){
		long long tmp=sum;
		tmp-=imos[i];
		if(tmp>ans)ans=tmp;
	}
	printf("%lld\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:10:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<n;i++)scanf("%d%d%d",&lrs[i][0],&lrs[i][1],&lrs[i][2]);
                  ^