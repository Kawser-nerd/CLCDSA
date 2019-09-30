#include <stdio.h>
int main(void){
	long long int n,s,t,w,a[1000]={0},best=0,i;
	scanf("%lld%lld%lld",&n,&s,&t);
	scanf("%lld",&w);
	if(w>=s && w<=t) best++;
	for(i=2;i<=n;i++){
		scanf("%lld",&a[i]);
		if(w+a[i]>=s && w+a[i]<=t) best++;
		w+=a[i];
	}
	printf("%lld\n",best);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld",&n,&s,&t);
  ^
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&w);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&a[i]);
   ^