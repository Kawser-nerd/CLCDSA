#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

typedef long long ll;

inline ll read()
{
	ll x=0;char ch=getchar();
	while(ch<'0' || '9'<ch)ch=getchar();
	while('0'<=ch && ch<='9')x=x*10+(ch^48),ch=getchar();
	return x;
}

const int N=1e5+9;
const int md=1e9+7;

ll n,x[N],a[2],p[2],sp[2];
ll f[N][2],sumf[N][2];

int main()
{
	n=read();
	a[0]=read();a[1]=read();

	for(int i=1;i<=n;i++)
		x[i]=read();
	x[0]=-1e18;

	p[0]=p[1]=sp[0]=sp[1]=0;
	f[0][0]=f[0][1]=sumf[0][0]=sumf[0][1]=1;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<=1;j++)
		{
			while(p[j]<i && x[i+1]-x[p[j]]>=a[j])
				p[j]++;
			f[i][j]=sumf[p[j]-1][j^1];
		}
		for(int j=0;j<=1;j++)
		{
			if(x[i+1]-x[i]<a[j])
				for(;sp[j]<i;sp[j]++)
					f[sp[j]][j]=sumf[sp[j]][j]=0;
			sumf[i][j]=(sumf[i-1][j]+f[i][j])%md;
		}
	}

	printf("%lld\n",(sumf[n-1][0]+sumf[n-1][1])%md);
	return 0;
}