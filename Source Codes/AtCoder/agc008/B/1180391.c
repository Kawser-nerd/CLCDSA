#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define FOR(i,a,n) for(int i=a;i<n;i++)
#define ll long long

ll a[100001];
ll b[100001];
 int main(void)
 {
 	int n,k;
 	ll res=0;
 	scanf("%d %d",&n,&k);
 	FOR(i,1,n+1){
 		scanf("%lld",&a[i]);
 		b[i]=MAX(0,a[i]);
 		a[i]+=a[i-1],b[i]+=b[i-1];
 	}
 	FOR(i,k,n+1){
 		ll p=a[i]-a[i-k];
 		ll q=b[n]-b[i]+b[i-k];
 		if(p>0) res=MAX(res,p+q);
 		else res=MAX(res,q);
 	}
 	printf("%lld",res);
 	return 0;
 } ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&k);
   ^
./Main.c:14:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%lld",&a[i]);
    ^