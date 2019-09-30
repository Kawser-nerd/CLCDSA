#include <stdio.h>

int main(){
	long long int N;
	long long int i,hoge,ans=0;
	
	scanf("%lld",&N);
	
	for(i=0;i<N;i++){
		scanf("%lld",&hoge);
		ans+=hoge-1;
	}
	
	printf("%lld",ans);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&N);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&hoge);
   ^