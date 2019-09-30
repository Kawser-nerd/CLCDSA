#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#define ALL(x) (x).begin(), (x).end()
#define dll(x) scanf("%I64d",&x)
#define xll(x) printf("%I64d\n",x)
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rep(i,x,n) for(int i=x;i<n;i++)
#define repd(i,x,n) for(int i=x;i<=n;i++)
#define pii pair<int,int>
#define pll pair<long long ,long long>
#define gbtb ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define MS0(X) memset((X), 0, sizeof((X)))
#define MSC0(X) memset((X), '\0', sizeof((X)))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define eps 1e-6
#define gg(x) getInt(&x)
#define db(x) cout<<"== [ "<<x<<" ] =="<<endl;
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll powmod(ll a,ll b,ll MOD){ll ans=1ll;while(b){if(b&1)ans=ans*a%MOD;a=a*a%MOD;b>>=1;}return ans;}
inline void getInt(int* p);
const int maxn=100010;
const int inf=0x3f3f3f3f;
/*** TEMPLATE CODE * * STARTS HERE ***/
bool noprime[maxn];
std::vector<int> p;
ll pf[122][3];
int init()
{
	MS0(noprime);
	p.clear();
	int m=(int)(sqrt(maxn+0.5));
	repd(i,2,m)
	{
		if(!noprime[i])
		{
			for(int j=i*i;j<=maxn;j+=i)
			{
				noprime[j]=1;
			}
		}
	}
	repd(i,2,maxn)
	{
		if(!noprime[i])
		{
			p.pb(i);
		}
	}
	return p.size();
}
int getprifac(ll n,int len)
{
	int pos=0;
	for(int i=0;p[i]*p[i]<=n&&i<len;i++)
	{
		if(n%p[i]==0)
		{
			pf[++pos][0]=p[i];
			pf[pos][1]=0;
			while(n%p[i]==0)
			{
				pf[pos][1]++;
				n/=p[i];
			}
		}
	}
	if(n>1)
	{
		pf[++pos][0]=n;
		pf[pos][1]=1;
	}
	return pos;
}
ll getnum(ll num,ll x)
{
	if(!num)
	{
		return 0;
	}else
	{
		return num/x+getnum(num/x,x);
	}
}
const ll mod = 1e9+7ll;
int main()
{
	//    freopen("C:\\Users\\DH_M\\Desktop\\code_io\\in.txt.txt","r",stdin);
	//    freopen("C:\\Users\\DH_M\\Desktop\\code_io\\out.txt.txt","w",stdout);
	ll n;
	cin>>n;
	int len=init();
	ll ans=1ll;
	rep(i,0,len)
	{
		if(p[i]>n)
			break;

		ll cnt=getnum(n,p[i]);
		ans*=(cnt+1ll);
		ans=(ans+mod)%mod;
	}
	cout<<ans<<endl;
	
	
    return 0;
}

inline void getInt(int* p) {char ch;do {ch = getchar();} 
while (ch == ' ' || ch == '\n');if (ch == '-') {*p = -(getchar() - '0');
while ((ch = getchar()) >= '0' && ch <= '9') {*p = *p * 10 - ch + '0';}}
else {*p = ch - '0';while ((ch = getchar()) >= '0' && ch <= '9') 
{*p = *p * 10 + ch - '0';}}}