#include<stdio.h>
typedef unsigned u;
u max(u a,u b){return a>b?a:b;}
u F[1111],O[1111],V[1111],vi;
int main()
{
	u t=0,T,n,i,j,k,r;
	for(scanf("%u",&T);t++<T;)
	{
		scanf("%u",&n);
		for(i=0;++i<=n;O[i]=0)scanf("%u",F+i);
		for(r=i=0;++i<=n;)
		{
			for(V[j=i]=++vi,k=1;V[j=F[j]]!=vi;++k)V[j]=vi;
			if(F[F[j]]==j)O[j]=max(O[j],k);
			if(i==j)r=max(r,k);
		}
		for(i=k=0;++i<=n;)if(O[i]){k+=O[i];if(F[i]<i)k-=2;}
		r=max(r,k);
		printf("Case #%u: %u\n",t,r);
	}
	return 0;
}
