#include<stdio.h>

int main(){
	int n,a,i,ans=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a);
		ans+=(80>a?80-a:0);
	}
	printf("%d\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^