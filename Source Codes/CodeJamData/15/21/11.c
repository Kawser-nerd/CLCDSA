#include <stdio.h>

long long int dp[1000001]={0};
long long int mins(long long int a,long long int b);
long long int dps(long long int a);

int main(void)
{
	long long int a,k,l,j;
	int T,i;
	FILE* in = fopen("A-large.in","r");
	FILE* out = fopen("oute.txt","w");

	fscanf(in,"%d",&T);

	dp[1]=1;

	for(i=1;i<=T;i++)
	{
		fscanf(in,"%I64d",&a);

		//j=dps(a);

		for(j=0;a;j++)
		{
			long long int b=0;
			int u=0;

			for(k=1;a>=k;k*=10)
				;

			k /= 10;

			if(a%10==1)
			{
				for(l=1;k;l*=10,k/=10)
				{
					if(l>k && k!=1 && (a/k)%10!=0)
					{
						u=1;
						break;
					}

					b += ((a/k)%10)*l;
				}

				if(b>=a || u)
					b=a-1;
			}

			else
				b=a-1;

			a=b;
		}

		fprintf(out,"Case #%d: %I64d\n",i,j);
		printf("%d\n",i);
	}

	fclose(in);
	fclose(out);

	return 0;
}

/*long long int dps(long long int a)
{
	long long int k,l;
	long long int b=0;

	if(dp[a]!=0)
		return dp[a];

	for(k=1;a>=k;k*=10)
		;

	k /= 10;
	
		for(l=1;k;l*=10,k/=10)
		{
			b += ((a/k)%10)*l;
		}

	if(a>b && a%10)
	{
		dp[a] = mins(dps(a-1),dps(b))+1;

		return dp[a];
	}

	else
	{
		dp[a]=dps(a-1)+1;

		return dp[a];
	}
}
long long int mins(long long int a,long long int b)
{
	if(a>b)
		return b;

	else return a;
}*/