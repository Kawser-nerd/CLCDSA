#include<stdio.h>

int main(int argc, char const *argv[]){
	long long n,t,now,ans=0,i,ti;
	scanf("%lld %lld",&n,&t);
	scanf("%lld",&now);
	ans+=t;
	for(i=1;i<n;i++){
		scanf("%lld",&ti);
		if(ti-now>=t) ans+=t;
		else ans+=ti-now;
		now=ti;
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld",&n,&t);
  ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&now);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&ti);
   ^