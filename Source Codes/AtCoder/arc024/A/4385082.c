#include<stdio.h>

int main(){
	int n,m,a[2][100],j,i,size[2][51]={0},ans=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)scanf("%d",&a[0][i]);
	for(i=0;i<m;i++)scanf("%d",&a[1][i]);
	for(i=0;i<n;i++)size[0][a[0][i]]++;
	for(i=0;i<m;i++)size[1][a[1][i]]++;
	for(i=0;i<=50;i++)ans+=(size[0][i]<size[1][i]?size[0][i]:size[1][i]);
	//for(i=0;i<=40;i++)printf("%d:%d\n",i,size[0][i]+size[1][i]);
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:6:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<n;i++)scanf("%d",&a[0][i]);
                  ^
./Main.c:7:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<m;i++)scanf("%d",&a[1][i]);
                  ^