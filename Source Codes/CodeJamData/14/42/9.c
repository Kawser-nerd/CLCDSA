#include<stdio.h>
typedef unsigned u;
u A[1111];
int main()
{
	u t=0,T,n,i,j,k,lo,hi,r;
	for(scanf("%u",&T);t++<T;)
	{
		scanf("%u",&n);
		for(i=0;i<n;scanf("%u",A+i++));
		r=lo=0;hi=n-1;
		while(lo!=hi)
		{
			for(k=A[i=j=lo];i++<hi;)if(A[i]<k){k=A[i];j=i;}
			if(j-lo>hi-j)
			{
				r+=hi-j;
				for(i=j;i<hi;i++)A[i]=A[i+1];
				A[hi--]=k;
			}
			else
			{
				r+=j-lo;
				for(i=j;i>lo;i--)A[i]=A[i-1];
				A[lo++]=k;
			}
		}
		printf("Case #%u: %u\n",t,r);
	}
	return 0;
}
