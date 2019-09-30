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
const int maxn=1010;
const int inf=0x3f3f3f3f;
/*** TEMPLATE CODE * * STARTS HERE ***/
int a[maxn];
int b[maxn];
int c[maxn];
int dp[55][maxn][567];
int n,ma,mb;

int main()
{
	//    freopen("C:\\Users\\DH_M\\Desktop\\code_io\\in.txt.txt","r",stdin);
	//    freopen("C:\\Users\\DH_M\\Desktop\\code_io\\out.txt.txt","w",stdout);
    gbtb;
    cin>>n>>ma>>mb;
    rep(i,0,n)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    repd(i,0,n)
    {
        repd(j,0,400)
        {
            repd(z,0,400)
            {
                dp[i][j][z]=inf;
            }
        }
    }
    dp[0][0][0]=0;
    rep(i,0,n)
    {
        repd(j,0,400)
        {
            repd(z,0,400)
            {
                if(dp[i][j][z]==inf)
                {
                    continue;
                }
                dp[i+1][j][z]=min(dp[i+1][j][z],dp[i][j][z]);
                dp[i+1][j+a[i]][z+b[i]]=min(dp[i+1][j+a[i]][z+b[i]],dp[i][j][z]+c[i]);
            }
        }
    }
    int ans=inf;
    repd(i,1,400)
    {
        repd(j,1,400)
        {
            if(i*mb==j*ma)
            {
                ans=min(ans,dp[n][i][j]);
            }
        }
    }
    ans=ans==inf?-1:ans;
    cout<<ans<<endl;


    return 0;
}

inline void getInt(int* p) {char ch;do {ch = getchar();}
while (ch == ' ' || ch == '\n');if (ch == '-') {*p = -(getchar() - '0');
while ((ch = getchar()) >= '0' && ch <= '9') {*p = *p * 10 - ch + '0';}}
else {*p = ch - '0';while ((ch = getchar()) >= '0' && ch <= '9')
{*p = *p * 10 + ch - '0';}}}