#include<cstdio>
#include<set>
#include<algorithm>
#define int long long
using namespace std;
struct man
{
	int a,b,c;
	bool operator<(const man &x)const{return a-b<x.a-x.b;}
}x[200000];
int f[200000],g[200000];
signed main()
{
	int a,b,c,ans=0;
	scanf("%lld%lld%lld",&a,&b,&c);
	for(int i=1;i<=a+b+c;i++)
	{
		scanf("%lld%lld%lld",&x[i].a,&x[i].b,&x[i].c);
		x[i].a-=x[i].c;
		x[i].b-=x[i].c;
		ans+=x[i].c;
	}
	sort(x+1,x+a+b+c+1);
	multiset<int> s;
	int tot1=0,tot2=0;
	for(int i=1;i<=a+b+c;i++)
	{
		s.insert(x[i].b);
		tot1+=x[i].b;
		if(s.size()>b)
		{
			tot1-=*s.begin();
			s.erase(s.begin());
		}
		f[i]=tot1;
	}
	s.clear();
	for(int i=a+b+c;i>0;i--)
	{
		s.insert(x[i].a);
		tot2+=x[i].a;
		if(s.size()>a)
		{
			tot2-=*s.begin();
			s.erase(s.begin());
		}
		g[i]=tot2;
	}
	int mx=-(1ll<<62);
	for(int i=b;i<=b+c;i++)mx=max(mx,f[i]+g[i+1]);
	printf("%lld\n",ans+mx);
	return 0;
}