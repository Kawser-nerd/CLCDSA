#include<stdio.h>
#include<stdlib.h>
typedef unsigned u;
typedef double d;
int F(const void*x,const void*y)
{
	if(*(d*)x>*(d*)y)return 1;
	if(*(d*)x<*(d*)y)return -1;
	return 0;
}
d N[1001],K[1001];
int main()
{
	u T,t=0,n,i,j,p;
	for(scanf("%u",&T);t++<T;)
	{
		scanf("%u",&n);
		for(i=0;i<n;scanf("%lf",N+i++));
		qsort(N,n,sizeof(d),F);
		for(i=0;i<n;scanf("%lf",K+i++));
		qsort(K,n,sizeof(d),F);
		printf("Case #%u: ",t);
		for(i=j=0;i<n;i++)if(N[i]>K[j])j++;
		printf("%u ",j);
		for(p=n,i=j=0;j<n;i++)
		{
			while(j<n&&N[i]>K[j])j++;
			if(j<n)p--;j++;
		}
		printf("%u\n",p);
	}
	return 0;
}
