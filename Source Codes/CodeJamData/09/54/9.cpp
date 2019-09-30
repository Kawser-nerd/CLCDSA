#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define oo 20000005
#define Mod 1000000007
typedef long long LL;
int Test,Case,N,M,K;
LL a[oo];
LL L,R;

inline void Prepare()
{
	for (LL n=10,p=1;n<=10000000;p=n,n*=10)
	{
		for (LL i=p;i<n;++i)
		{
			LL k=0;
			for (LL j=i/10;j;j/=10)
				k=k*10+j%10;
			k+=i*n/10;
			a[++N]=k;
		}
		if (n<10000000)
		for (LL i=p;i<n;++i)
		{
			LL k=0;
			for (LL j=i;j;j/=10)
				k=k*10+j%10;
			k+=i*n;
			a[++N]=k;
		}
	}
}

inline void Readin()
{
	scanf("%I64d%I64d\n",&L,&R);
}

LL Sum(LL a)
{
	return a*(a-1)/2%Mod;
}

inline void Solve()
{
	LL Ans=0,X[2]={};
	--L;
	
	for (int i=1;i<=N;++i)
	{
		LL x=i==1?0:a[i-1],y=a[i]-1;
		if (y>=L)
		{
			x=max(L,x);
			y=min(y,R-1);
			if (x<=y)
			X[i-1&1]+=y-x+1;
		}
		X[i-1&1]%=Mod;
		x=a[i],y=i==N?a[N]+1:a[i+1]-1;
		
		if (x<=R)
		{
			LL xx=x;
			x=max(x,L+1);
			y=min(y,R);
			if (x<=y)
			Ans=(Ans+(y-x+1)*X[i&1]+Sum(y-max(xx,L)+1))%Mod;
		}
	}
	
	printf("%I64d\n",Ans);
}

int main()
{
	//freopen("i.txt","r",stdin);
	
	Prepare();
	for (scanf("%d",&Test);Test--;)
	{
		printf("Case #%d: ",++Case);
		
		Readin();
		Solve();
	}
	
	return 0;
}
