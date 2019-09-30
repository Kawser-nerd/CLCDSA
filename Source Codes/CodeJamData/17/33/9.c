#include <stdio.h>

int main()
{
	int i,j,k,m,n;
	int t,T;
	long double u,uu;
	long double p[100], x;
	long double sum[100];
	long double a,b;	
		
	scanf("%d", &T);
	for(t=1;t<=T;t++)
	{
		scanf("%d%d", &n,&k);
		scanf("%Lf", &u);
		
		for(i=0;i<n;i++)
		{
			scanf("%Lf", &p[i]);
		}
		
		for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		if(p[i]>p[j]) 
		{
			x = p[i]; p[i]=p[j]; p[j]=x;
		}
		
		sum[0] = p[0];
		for(i=1;i<n;i++) sum[i]=sum[i-1]+p[i];
		
		/*for(i=0;i<n;i++)
		{
			printf("%Lf ", sum[i]);
		}
		printf("  sum\n");
		*/
		
		for(m=0;m<n;m++)
		{
			b = (long double)(sum[m]+u)/(m+1);
			if(p[m]>b) break;
			//printf("m=%d  p=%Lf  b=%Lf\n",m,p[m],b);
		}		
		
		a=1.0;
		b = (long double)(sum[m-1]+u)/(m);
		for(i=0;i<m;i++) a=a*b;
		for(i=m;i<n;i++) a=a*p[i];		
		
		for(i=0;i<n;i++)
		{
			//printf("%Lf ", p[i]);
		}
		
		//printf("%Lf\n", u);
			
		printf("Case #%d: %6Lf\n",t, a);
	}
	
	return 0;
	
}