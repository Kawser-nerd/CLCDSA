#include<stdio.h>
#define max(a,b) a>b?a:b
long long int d[1005],h[1005];
long long int m[1005],pl,ti,pi;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	long long int t,T,n,i,p,ans;
	scanf("%lld",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%lld %lld %lld",&d[i],&h[i],&m[i]);
		if(n==1)
		{
			if(h[0]==2)
			{
				h[0]=1;
				h[1]=1;
				m[1]=m[0]+1;
				d[1]=d[0];
				n=2;
			}
		}
		
//		for(i=0;i<n;i++)
//			m[i]=m[i]*360;
		
		if(n>1 && d[0]>d[1])
		{
			p=d[0];
			d[0]=d[1];
			d[1]=p;
			
			pl=m[0];
			m[0]=m[1];
			m[1]=pl;
		}
		
		if(n==1)
		{
			ans=0;
		}
		else
		{
			if(m[1]<m[0])   //slow-fast
			{
				ti=m[0]*(360-d[0]);
				pi=m[1]*(360-d[1]+360);
				
				if(ti<pi)
					ans=0;
				else
				{
					ans=1;
				}
			}
			else if(m[1]==m[0])
			{
				ans=0;
			}
			else //fast-slow
			{
				ti=m[0]*(360-d[0]);
				pi=m[1]*(360-d[1]);
				
				if(ti>=pi)
				{
					ans=0;
				}
				else
				{
					ti=m[0]*(360-d[0]+360);
					
					if(ti>pi)
						ans=0;
					else
						ans=1;
				}
				
				
//				ti=m[1]*(360-d[1]);
//				pi=m[0]*(360-d[0]+360);
//				
//				if(ti<pi)
//					ans=0;
//				else
//				{
//					ans=1;
//				}

				
			}
		}
		
		printf("Case #%lld: %lld\n",t,ans);
	}
	return 0;
}
