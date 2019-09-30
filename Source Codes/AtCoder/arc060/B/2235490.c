#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

ll n,s;
int main(){
	scanf("%lld%lld",&n,&s);
	
	if(n<s){
		puts("-1");
		return 0;
	}
	
	if(n==s){
		printf("%lld\n",n+1);
		return 0;
	}
	
	rep(b,2,400000){
		ll sum=0,temp=n;
		while(temp){
			sum+=temp%b;
			temp/=b;
		}
		if(sum==s){
			printf("%lld\n",b);
			return 0;
		}
	}
	
	//2?
	for(ll p=sqrt(n-s);p>=1;p--)if((n-s)%p==0){
		ll b=(n-s)/p+1;
		ll q=s-p;
		if(0<=q&&q<b){
			printf("%lld\n",b);
			return 0;
		}
	}
	
	puts("-1");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&s);
  ^