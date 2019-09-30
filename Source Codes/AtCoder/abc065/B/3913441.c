#include<stdio.h>

int main(){
	int n,a[100000],i,f[100000]={0},ans=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	i=0;
	while(1){
		if(f[i]==1){
			puts("-1");
			return 0;
		}else if(i==1){
			printf("%d\n",ans);
			return 0;
		}
		else {
			f[i]++;
			i=a[i]-1;
			ans++;
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:6:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<n;i++)scanf("%d",&a[i]);
                  ^