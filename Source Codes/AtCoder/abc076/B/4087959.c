#include<stdio.h>

int main(){
	int n,k,ans=1,i;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++){
		if(ans<k){
			ans=ans*2;
		}else ans+=k;
	}
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&k);
  ^