#include <stdio.h>

int main(){
	int a,b;
	int i;
	int ans=0;
	
	scanf("%d %d",&a,&b);
	
	for(i=1;i<b-a;i++){
		ans+=i;
	}
	
	ans-=a;
	
	printf("%d",ans);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&a,&b);
  ^