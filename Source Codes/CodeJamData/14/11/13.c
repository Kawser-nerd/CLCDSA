#include<stdio.h>
#include<stdlib.h>
typedef long long unsigned llu;
typedef unsigned u;
int F(const void*x,const void*y)
{
	if(*(llu*)x>*(llu*)y)return 1;
	if(*(llu*)x<*(llu*)y)return-1;
	return 0;
}
u n,l;
llu N[200],L[200],Li[200];
u ok(llu f)
{
	u i,j;
	for(i=0;i<n;i++)Li[i]=L[i]^f;
	qsort(Li,n,sizeof(llu),F);
	for(i=j=0;i<n&&j<n;)
	{
		while(Li[j]<N[i])j++;
		if(Li[j]!=N[i])return 0;
		i++;j++;
	}
	return i==n;
}
u bit(llu k)
{
	if(k==0)return 0;
	u r=1;
	while(k^=k&-k)r++;
	return r;
}
int main()
{
	u t=0,T,i,j,k,r=100;char c;llu I;
	for(scanf("%u",&T);t++<T;r=100)
	{
		scanf("%u%u",&n,&l);
		for(i=0;i<n;i++)
		{
			I=0;
			while((c=getchar())<'0');
			for(I=c&15;(c=getchar())>='0';I=(I<<1)|(c&15));
			N[i]=I;
		}
		qsort(N,n,sizeof(llu),F);
		for(i=0;i<n;i++)
		{
			I=0;
			while((c=getchar())<'0');
			for(I=c&15;(c=getchar())>='0';I=(I<<1)|(c&15));
			L[i]=I;
		}
		for(i=0;i<n;i++)for(j=0;j<n;j++)
		{
			if(ok(N[i]^L[j]))
			{
				k=bit(N[i]^L[j]);
				if(k<r)r=k;
			}
		}
		printf("Case #%u: ",t);
		if(r==100)printf("NOT POSSIBLE\n");
		else printf("%u\n",r);
	}
	return 0;
}
