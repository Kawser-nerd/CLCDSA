#include <stdio.h>
long long  gcd(long long x,long long y){
	if(y==0) return x;
	else return gcd(y,x%y);
}
int main(){
	int t,i;
	long long m,n,c,sum;
	sum=0;
	while(~scanf("%d",&t)){
	scanf("%lld",&m);
	for(i=1;i<t;i++){
		scanf("%lld",&n);
		c=gcd(m,n);
		m=m/c*n;
		}
	printf("%lld\n",m);
	}
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&m);
  ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&n);
   ^