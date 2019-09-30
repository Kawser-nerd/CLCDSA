#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

ll a[20010];
ll b[20010];
main(){
	int n;
	scanf("%d",&n);
	rep(i,0,n){
		int t;
		scanf("%d",&t);
		a[--t]=i+1;
	}
	rep(i,1,n){
		if(a[i]<=a[i-1]){
			b[i]-=(a[i-1]+1)-a[i];
			a[i]+=(a[i-1]+1)-a[i];
		}
		if(b[i]>=b[i-1]){
			a[i]+=b[i]-(b[i-1]-1);
			b[i]-=b[i]-(b[i-1]-1);
		}
	}
	
	rep(i,0,n)printf("%lld%c",a[i],i==n-1?'\n':' ');
	rep(i,0,n)printf("%lld%c",b[i]-b[n-1]+1,i==n-1?'\n':' ');
	return 0;
} ./Main.c:8:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&t);
   ^