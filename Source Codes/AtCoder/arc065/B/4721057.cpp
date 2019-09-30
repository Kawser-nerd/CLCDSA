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
#define rt return
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
ll powmod(ll a,ll b,ll MOD){ll ans=1;while(b){if(b%2)ans=ans*a%MOD;a=a*a%MOD;b/=2;}return ans;}
inline void getInt(int* p);
const int maxn=1000010;
const int inf=0x3f3f3f3f;
/*** TEMPLATE CODE * * STARTS HERE ***/
int par[maxn];
int par2[maxn];
int n;
int m1,m2;
void init()
{
	repd(i,0,n)
	{
		par[i]=i;
		par2[i]=i;
	}
}
int findpar(int x)
{
	return x==par[x]?x:par[x]=findpar(par[x]);
}
int findpar2(int x)
{
	return x==par2[x]?x:par2[x]=findpar2(par2[x]);
}
void merg(int x,int y)
{
	x=findpar(x);
	y=findpar(y);
	if(x!=y)
	{
		par[x]=y;
	}
}
void merg2(int x,int y)
{
	x=findpar2(x);
	y=findpar2(y);
	if(x!=y)
	{
		par2[x]=y;
	}
}
std::vector<int> v[maxn];
// std::vector<int> v2[];

int main()
{
    //freopen("D:\\common_text\\code_stream\\in.txt","r",stdin);
	//freopen("D:\\common_text\\code_stream\\out.txt","w",stdout);
	gg(n);
	gg(m1);
	gg(m2);
	init();
	int a,b;
	repd(i,1,m1)
	{
		gg(a);
		gg(b);
//		v[a].pb(b);
//		v[b].push_back(a);
		merg(a,b);
	}
	repd(i,1,m2)
	{
		gg(a);
		gg(b);
//		v[a].pb(b);
//		v[b].push_back(a);
		merg2(a,b);
	}
	map<pii,int> ans;
	repd(i,1,n)
	{
//	    sort(ALL(v[i]));
//	    v[i].erase(unique(ALL(v[i])),v[i].end());
        ans[mp(findpar(i),findpar2(i))]++;
//		int cnt=0;
//		repd(x,1,n)
//		{
//			if((findpar(i)==findpar(x))&&(findpar2(i)==findpar2(x)))
//			{
//				cnt++;
//			}
//		}
////		cnt++;
//		printf("%d ",cnt);
	}
    repd(i,1,n)
    {
        cout<<ans[mp(findpar(i),findpar2(i))]<<" ";
    }

    return 0;
}

inline void getInt(int* p) {
    char ch;
    do {
        ch = getchar();
    } while (ch == ' ' || ch == '\n');
    if (ch == '-') {
        *p = -(getchar() - '0');
        while ((ch = getchar()) >= '0' && ch <= '9') {
            *p = *p * 10 - ch + '0';
        }
    }
    else {
        *p = ch - '0';
        while ((ch = getchar()) >= '0' && ch <= '9') {
            *p = *p * 10 + ch - '0';
        }
    }
}