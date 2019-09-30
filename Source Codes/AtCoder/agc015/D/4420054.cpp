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
const int maxn=1000010;
const int inf=0x3f3f3f3f;
/*** TEMPLATE CODE * * STARTS HERE ***/
ll bas[2323];
int main()
{
	//    freopen("C:\\Users\\DH_M\\Desktop\\code_io\\in.txt.txt","r",stdin);
	//    freopen("C:\\Users\\DH_M\\Desktop\\code_io\\out.txt.txt","w",stdout);
	ll a,b;
	cin>>a>>b;
	if(a==b)
    {
        return !printf("1\n");
    }
	ll ans=0ll;
	bas[0]=1;
	repd(i,1,60)
	{
		bas[i]=bas[i-1]*2ll;
	}
	int d=60;
	while((a&bas[d])==(b&bas[d]))
		d--;
	a&=bas[d+1]-1;
	b&=bas[d+1]-1;
	ll l1=a;
	ll r1=bas[d];
	ans+=(r1-l1+1ll);
	int k=d-1;
	while(k>=0&&!(b&(bas[k])))
		k--;
	ll l2=bas[d];
	ll r2=bas[d]+bas[k+1]-1;
	ans+=(r2-l2);
	ll l3=bas[d]+a;
	ll r3=bas[d+1]-1;
	l3=max(l3,r2+1);
	ans+=r3-l3+1;
	cout<<ans<<endl;


    return 0;
}

inline void getInt(int* p) {char ch;do {ch = getchar();}
while (ch == ' ' || ch == '\n');if (ch == '-') {*p = -(getchar() - '0');
while ((ch = getchar()) >= '0' && ch <= '9') {*p = *p * 10 - ch + '0';}}
else {*p = ch - '0';while ((ch = getchar()) >= '0' && ch <= '9')
{*p = *p * 10 + ch - '0';}}}