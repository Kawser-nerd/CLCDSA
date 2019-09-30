#include <stdio.h>

int main()
{
	long long int a,b,k,l;
	scanf("%lld %lld %lld %lld",&a,&b,&k,&l);

	long long int m1,m2,tmp1,tmp2,tmp3,ans,m3;

	//just pattern A
	tmp1=k/l;
	tmp3=k-(l*tmp1);

	m1=b*tmp1+a*tmp3;

	//pattern B
	tmp2=(k/l)+1;
	m2=b*tmp2;

	//pattern C(each buy)
	m3=a*k;

	ans=m1;
	if(ans>m2)
		ans=m2;
	if(ans>m3)
		ans=m3;
	

	printf("%lld\n",ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld %lld %lld",&a,&b,&k,&l);
  ^