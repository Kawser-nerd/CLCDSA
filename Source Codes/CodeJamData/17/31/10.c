#include <stdio.h>

int main()
{
	int i,j,k,m,n,x;
	int T,t;
	int r[2000];
	int h[2000];
	long double a[2000], aa[2000];
	long double pi=3.14159265358979;
	long double b,c;
	long double sum, max,best;
	
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%d%d",&n,&k);
		//printf("%d %d\n", n,k);
		
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&r[i],&h[i]);
			a[i]=(long double)2.0*pi*r[i]*h[i];
			aa[i] = (long double)pi*r[i]*r[i] + a[i];
		}
		
		for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		{
			if(a[i]<a[j])
			{
				b=a[i]; a[i]=a[j]; a[j]=b;
				b=aa[i]; aa[i]=aa[j]; aa[j]=b;
				m=r[i]; r[i]=r[j]; r[j]=m;
				m=h[i]; h[i]=h[j]; h[j]=m;
			}
		}

		//for(i=0;i<n;i++)
		{
			//printf("r=%d  h=%d  %LF  %LF\n", r[i], h[i], a[i], aa[i]);

		}
		
		best=0.0;
		for(i=0;i<n;i++)
		{
			sum = aa[i];
			m=k;
			if(i>=k) m--;
			for(j=0;j<m;j++)
			{
				if(i==j)
				{
					continue;
				}
				sum+=a[j];
			}
			if(sum>best) best=sum;
		}
		printf("Case #%d: %0.9Lf\n", t, best);
		
	}
	return 0;
}

