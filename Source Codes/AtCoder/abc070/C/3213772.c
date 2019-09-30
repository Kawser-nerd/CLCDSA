#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ll long long 

ll int GCD(ll int x,ll int y){return y==0? x:GCD(y,x%y);}

int main(void){
	int n,i;
	scanf("%d",&n);
	ll int t,ans,t1;
	scanf("%lld",&t);
	ans = t;
	for(i=1;i<n;i++){
		scanf("%lld",&t1);
		ans = t/GCD(t,t1)*t1;
		t = ans;
	}
	printf("%lld",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&t);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&t1);
   ^