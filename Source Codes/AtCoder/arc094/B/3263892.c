#include<stdio.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define min(p,q)((p)<(q)?(p):(q))

/*
A?B????????????N=AB????
x[i]*y[i]?N??????????????????
z=floor(?(N-1))????
x[i]?z or y[i]?z????????????2z???????????
??z(z+1)?N??x[i]=z?y[i]=z?????????-1
??A?z??x[i]=A?????????-1
?2???????
*/

int main(){
	ll q;
	scanf("%lld",&q);
	while(q--){
		ll a,b;
		scanf("%lld%lld",&a,&b);		
		ll n=a*b;
		//n-1?2^53?????????????
		ll c=sqrt(n-1)-1;
		while((c+1)*(c+1)<=n-1)c++;
		//
		ll ans=2*c;
		if(c*(c+1)>=n)ans--;
		if(min(a,b)<=c)ans--;
		printf("%lld\n",ans);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:8: warning: implicit declaration of function ‘sqrt’ [-Wimplicit-function-declaration]
   ll c=sqrt(n-1)-1;
        ^
./Main.c:24:8: warning: incompatible implicit declaration of built-in function ‘sqrt’
./Main.c:24:8: note: include ‘<math.h>’ or provide a declaration of ‘sqrt’
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&q);
  ^
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&a,&b);  
   ^