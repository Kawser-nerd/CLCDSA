#include<stdio.h>

#define N 100001

int main(){
	int n,m,i,f[N]={0},a[N];
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)scanf("%d",&a[i]);
	for(i=m-1;i>=0;i--){
		if(f[a[i]]==0){
			printf("%d\n",a[i]);
			f[a[i]]++;
		}
	}
	for(i=1;i<=n;i++){
		if(f[i]==0)printf("%d\n",i);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:8:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<m;i++)scanf("%d",&a[i]);
                  ^