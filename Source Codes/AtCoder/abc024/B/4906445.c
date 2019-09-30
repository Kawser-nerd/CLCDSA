#include <stdio.h>
#include <stdlib.h>
int main(void){
	int n,t,time=0,ans=0;
	scanf("%d%d",&n,&t);
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		if(time>a){
			ans += t-(time-a);
			time=a+t;
		}else{
			time = a+t;
			ans += t;
		}
	}
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&t);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^