#include <stdio.h>
int main(void){
	long long int l,h,n,a,v,i;
	scanf("%lld%lld%lld",&l,&h,&n);
	for(i=0;i<n;i++){
		scanf("%lld",&a);
		if(a<l) a=l-a;
		else if(a>h) a=-1;
		else a=0;
		printf("%lld\n",a);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld",&l,&h,&n);
  ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&a);
   ^