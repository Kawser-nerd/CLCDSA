#include<stdio.h>

long long R,K,N,M;
long long a[2000],sum[2000],next[2000],add[2000],cost[2000],flag[2000],q[2000];

int main()
{
	long long i,j,x,l,r,cc,dx,T,total,result;
	freopen("C-large.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%lld",&T);
	for(cc=1;cc<=T;cc++)
	{
		scanf("%lld %lld %lld",&R,&K,&N);
		for(i=0;i<N;i++)
			scanf("%lld",&a[i]);
	
		for(dx=0;dx<N;dx++)
		{		
            total=0;			
            for(i=0;i<N;i++)
			{
                j=dx+i;
				if(j>=N)
					j-=N;
				total+=a[j];
				next[dx]=j;
				cost[dx]=total;
				if(total>K)
				{
					cost[dx]=total-a[j];
					break;
				}
				else if(i==N-1)
					next[dx]=dx;
			}
		}

		for(i=0;i<N;i++)
			flag[i]=1;
		x=0;M=0;
        for(i=0;flag[x]>0;i++)
		{
			flag[x]=-i;
			q[M++]=x;
			x=next[x];
		}
        l=-flag[x],r=i;

		M=r-l;

		for(i=0;i<l;i++)
		{
			if(i==0)
				sum[i]=cost[q[i]];
			else
			    sum[i]=sum[i-1]+cost[q[i]];
		}

		for(i=l;i<r;i++)
		{
			if(i==l)
				add[i-l]=cost[q[i]];
			else
				add[i-l]=add[i-l-1]+cost[q[i]];
		}


		if(R<=l)
			result=sum[R-1];
		else
		{
			result=sum[l-1];
			R=R-l;
            result+=(R/M)*add[M-1];
			if((R%M)!=0)
                result+=add[(R%M)-1];
		}


        printf("Case #%lld: %lld\n",cc,result);
	}
	return 0;
}
