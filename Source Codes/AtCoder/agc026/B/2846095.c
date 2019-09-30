#include <stdio.h>

long long int gcd(long long a,long long b){
	long long int tmp;
	if(a<b){
		tmp=a;
		a=b;
		b=tmp;
	}
	if(b==0)return a;
	return gcd(b,a%b);
}

main(){

	int T;
	long long int a,b,c,d;/*
	scanf("%lld %lld",&a,&b);
	printf("%lld\n",gcd(a,b));
	return 0;*/
	long long m;
	scanf("%d",&T);
	while(T-->0){
		scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
		if(a<b || d < b){
			puts("No");
			continue;
		}
		a%=b;
		d%=b;
		if(c>b || (a<=c&&d==0)){
			puts("Yes");
			continue;
		}else if(d==0){
			puts("No");
			continue;
		}
//		puts("muzu");
		// b > c
		m=gcd(b,d);
		a+=(c-a)/m*m;
		if(a+m>=b)
			puts("Yes");
		else
			puts("No");
	}
} ./Main.c:14:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&T);
  ^
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
   ^