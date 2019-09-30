#include<stdio.h>
typedef unsigned u;
typedef double d;
d p,c,x;
d f(d s)
{
	if(c/s+x/(p+s)<x/s)return c/s+f(p+s);
	return x/s;
}
int main()
{
	u T,t=0,n,i,j,k;
	for(scanf("%u",&T);t++<T;)
	{
		scanf("%lf%lf%lf",&c,&p,&x);
		printf("Case #%u: %.7lf\n",t,f(2.0));
	}
	return 0;
}
