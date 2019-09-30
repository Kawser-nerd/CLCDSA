#include<stdio.h>
#include<stdlib.h>

#define min(a,b) ((a)<(b)?(a):(b))

int main(){
	int n,k,i,x,ans=0;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		ans+=min(abs(x-k),abs(x))*2;
	}
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&k);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&x);
   ^