#include<stdio.h>
#include <stdlib.h>

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	long a[50][2],c[50][2];
	int i,j;
	for(i=0;i<n;i++)scanf("%ld%ld",&a[i][0],&a[i][1]);
	for(i=0;i<m;i++)scanf("%ld%ld",&c[i][0],&c[i][1]);
	for(i=0;i<n;i++){
		long min=200000001;
		int ans;
		for(j=0;j<m;j++){
			if(abs(a[i][0]-c[j][0])+abs(a[i][1]-c[j][1])<min){
				min=abs(a[i][0]-c[j][0])+abs(a[i][1]-c[j][1]);
				ans=j;
			}
		}
		printf("%d\n",ans+1);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:9:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<n;i++)scanf("%ld%ld",&a[i][0],&a[i][1]);
                  ^
./Main.c:10:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<m;i++)scanf("%ld%ld",&c[i][0],&c[i][1]);
                  ^