#include<stdio.h>
long long gbs(long long a,long long b){
	long long i,m,n,temp;
	m=a;
	n=b;
	if(m<n){
		temp=m;
		m=n;
		n=temp;
	}
	if(a<b){
		temp=a;
		a=b;
		b=temp;
	}
	for(;n!=0;){
		temp=m%n;
		m=n;
		n=temp;
	}
	return a/m*b;
} 
main(){
	long long n,a[100],i,m;
	while(scanf("%lld",&n)!=EOF){
		m=1;
		for(i=0;i<=n-1;i++){
			scanf("%lld",&a[i]);
			m=gbs(m,a[i]);
		}
		printf("%lld\n",m);
	}
} ./Main.c:23:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:28:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%lld",&a[i]);
    ^