#include<cstdio>

const int AMP = -1;
const int EMP = -2;

int prime[1000005],tot;
int a[15];
int D,K;

void prepare()
{
	tot = 0;
	for(int i=2;i<=1000000;i++)
	{
		prime[++tot] = i;
		for(int j=1;j<tot && prime[j]*prime[j]<=i;j++)
			if( i%prime[j]==0 )
		{
			tot--;break;
		}
	}
}

int limit;

int eqA[15],eqB[15];

long long pw( long long a,long long b,long long c )
{
	long long ans = 1,tmp=a%c;
	while(b)
	{
		if(b&1) ans=ans*tmp%c;
		b/=2;
		tmp = tmp*tmp%c;
	}
	return ans;
}
int solve( int p )
{
	for(int i=1;i<=K;i++) if( p<=a[i] ) return EMP;

	for(int i=1;i<K;i++) if(a[i]==a[K]) return a[i+1];
	if(K<3) return AMP;

	for(int i=1;i+2<=K;i++)
	{
		eqA[i] = (a[i+1]-a[i])%p;if(eqA[i]<0) eqA[i]+=p;
		eqB[i] = (a[i+2]-a[i+1])%p;if(eqB[i]<0) eqB[i]+=p;
	}

	long long A = (eqB[1] * pw( eqA[1],p-2,p )) %p;
	long long B = (a[2]-a[1]*A)%p;if(B<0) B+=p;
	for(int i=1;i+2<=K;i++)
		if( (eqA[i]*A)%p != eqB[i] )  return EMP;

	return (a[K]*A+B)%p;
}
int main()
{
	prepare();

	int T,TT;
	scanf("%d",&TT);
	T = 0;
	int ans;
	while(TT--)
	{
		printf("Case #%d: ",++T);
		scanf("%d%d",&D,&K);
		limit = 1;for(int j=1;j<=D;j++) limit*=10;
		for(int i=1;i<=K;i++) scanf("%d",a+i);

		ans = EMP;
		for(int i=1;i<=tot && prime[i]<=limit;i++)
		{
			int tmp = solve(prime[i]);
			if( tmp!=EMP )
			{
				if( tmp==AMP )
				{
					ans = AMP;break;
				}else
				if( ans==EMP ) ans = tmp;else
				if( ans!=tmp )
				{
					ans = AMP;break;
				}
			}
		}
		if( ans==AMP ) printf("I don't know.\n");else
			printf("%d\n",ans);
	}
	return 0;
}

