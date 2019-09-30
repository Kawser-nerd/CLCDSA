#include <stdio.h>
int main(void){
	long long int n,t[100],m,p,x,i,j,v=0;
	scanf("%lld",&n);
	for(i=0;i<n;i++){
		scanf("%lld",&t[i]);
		v+=t[i];
	}
	scanf("%lld",&m);
	for(i=0;i<m;i++){
		scanf("%lld%lld",&p,&x);
		printf("%lld\n",v+x-t[p-1]);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&t[i]);
   ^
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&m);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&p,&x);
   ^