#include<stdio.h>

int main(){
	int t,n;
	scanf("%d%d",&t,&n);
	int i,m,a[n];
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	scanf("%d",&m);
	int b[m];
	for(i=0;i<m;i++)scanf("%d",&b[i]);
	if(n<m){
		puts("no");
		return 0;
	}
	int j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(a[j]!=0){
				if(b[i]>=a[j]&&b[i]-a[j]<=t){
					a[j]=0;
					break;
				}
				else if(j==n-1){
					puts("no");
					return 0;
				}
			}
		}
	}
	puts("yes");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&t,&n);
  ^
./Main.c:7:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<n;i++)scanf("%d",&a[i]);
                  ^
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&m);
  ^
./Main.c:10:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<m;i++)scanf("%d",&b[i]);
                  ^