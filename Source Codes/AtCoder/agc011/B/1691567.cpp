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

const int N=100009;

struct guo
{
	ll v,id;
	bool operator < (guo o)const
	{
		return v<o.v;
	}
}p[N];

ll n,a[N];

int main()
{
	n=read();
	for(int i=1;i<=n;i++)
		p[i].v=read(),p[i].id=i;
	sort(p+1,p+n+1);

	ll block;
	for(int i=1;i<=n;i++)
	{
		a[i]=a[i-1]+p[i].v;
		if(p[i].v>a[i-1]*2)
			block=i-1;
	}

	printf("%lld\n",n-block);
	return 0;
}