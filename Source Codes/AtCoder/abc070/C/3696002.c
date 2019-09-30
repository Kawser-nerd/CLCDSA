#include<stdio.h>
long long gcd(long long a,long long b)
{
    return !b?a:gcd(b,a%b);
}
int main() 
{
	int n;
	long long t,i,lcm=1;
	
	scanf("%d",&n);
	scanf("%lld",&lcm);//???lcm???????????????
	for(i=1;i<n;i++)
	{
		scanf("%lld",&t);//t????????????? 
		lcm=lcm/gcd(lcm,t)*t;
	}
		
	printf("%lld\n",lcm);	
	return 0;	
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&lcm);//???lcm???????????????
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&t);//t????????????? 
   ^