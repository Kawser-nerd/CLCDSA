#include <stdio.h>
typedef long long LL;
LL n,x;
LL gcd(LL a,LL b){
	if(a<b)a^=b,b^=a,a^=b;
	if(a%b==0) return b;
	return gcd(a%b,b);
}
int main(){
	scanf("%lld%lld",&n,&x);
	printf("%lld",(n-gcd(n,x))*3);
}