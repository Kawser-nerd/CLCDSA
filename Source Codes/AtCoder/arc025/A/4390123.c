#include<stdio.h>

int main(){
	int i,ans=0,a[7],b[7];
	for(i=0;i<7;i++)scanf("%d",&a[i]);
	for(i=0;i<7;i++)scanf("%d",&b[i]);
	for(i=0;i<7;i++)ans+=(a[i]>b[i]?a[i]:b[i]);
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<7;i++)scanf("%d",&a[i]);
                  ^
./Main.c:6:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<7;i++)scanf("%d",&b[i]);
                  ^