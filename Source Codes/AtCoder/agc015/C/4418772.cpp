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
const int N=2003;
struct node
{
	int hang;
	int lie;
	int v;
}dp[N][N];
char a[N][N];
int n,m,q;
int x1,x2,y11,y2;
int main()
{
	//    freopen("C:\\Users\\DH_M\\Desktop\\code_io\\in.txt.txt","r",stdin);
	//    freopen("C:\\Users\\DH_M\\Desktop\\code_io\\out.txt.txt","w",stdout);
	gbtb;
	cin>>n>>m>>q;
	repd(i,1,n)
	{
		repd(j,1,m)
		{
			cin>>a[i][j];
		}
	}
	repd(i,1,n)
	{
		repd(j,1,m)
		{
			dp[i][j].v=dp[i][j-1].v+dp[i-1][j].v-dp[i-1][j-1].v+(a[i][j]=='1'?1:0);
			dp[i][j].lie=dp[i][j-1].lie+dp[i-1][j].lie-dp[i-1][j-1].lie;
			dp[i][j].hang=dp[i][j-1].hang+dp[i-1][j].hang-dp[i-1][j-1].hang;

			if(a[i][j]=='1')
			{
				if(a[i][j]==a[i-1][j])
				{
					dp[i][j].lie++;
				}
				if(a[i][j]==a[i][j-1])
                {
                    dp[i][j].hang++;
//                    num++;
                }
			}

		}
	}
	repd(qq,1,q)
	{
		cin>>x1>>y11>>x2>>y2;
		int cnt=dp[x2][y2].v-dp[x2][y11-1].v-dp[x1-1][y2].v+dp[x1-1][y11-1].v;
		cnt-=dp[x2][y2].hang-dp[x2][y11].hang-dp[x1-1][y2].hang+dp[x1-1][y11].hang;
		cnt-=dp[x2][y2].lie-dp[x1][y2].lie-dp[x2][y11-1].lie+dp[x1][y11-1].lie;
		cout<<cnt<<endl;
	}


    return 0;
}

inline void getInt(int* p) {char ch;do {ch = getchar();}
while (ch == ' ' || ch == '\n');if (ch == '-') {*p = -(getchar() - '0');
while ((ch = getchar()) >= '0' && ch <= '9') {*p = *p * 10 - ch + '0';}}
else {*p = ch - '0';while ((ch = getchar()) >= '0' && ch <= '9')
{*p = *p * 10 + ch - '0';}}}