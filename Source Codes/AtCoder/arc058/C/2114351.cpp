#include <iostream>
#include <vector>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto& (a): (b))
#define all(v) (v).begin(),(v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define spair(p) cout<<#p<<": "<<p.fi<<" "<<p.se<<endl
#define sar(a,n) cout<<#a<<":";rep(kbrni,n)cout<<" "<<a[kbrni];cout<<endl
#define svec(v) cout<<#v<<":";rep(kbrni,v.size())cout<<" "<<v[kbrni];cout<<endl
#define svecp(v) cout<<#v<<":";each(kbrni,v)cout<<" {"<<kbrni.first<<":"<<kbrni.second<<"}";cout<<endl
#define sset(s) cout<<#s<<":";each(kbrni,s)cout<<" "<<kbrni;cout<<endl
#define smap(m) cout<<#m<<":";each(kbrni,m)cout<<" {"<<kbrni.first<<":"<<kbrni.second<<"}";cout<<endl

using namespace std;

typedef pair<int,int> P;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<P> vp;
typedef vector<string> vs;

const int MAX_N = 100005;
const int m = 18;

ll dp[41][(1 << m)];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vi a(3);
    rep(i,3){
        cin >> a[i];
    }
    a[1] += a[2],a[0] += a[1];
    int z = 0;
    rep(i,3){
        z |= (1 << (m-1-a[i]));
    }
    ll ans = 1;
    rep(i,n){
        ans = (ans*10) % MOD;
    }
    dp[0][(1 << (m-1))] = 1;
    rep(i,n){
        rep(j,(1 << m)){
            srep(k,1,11){
                int nj = ((j >> k)|(1 << (m-1)));
                if((nj&z) != z){
                    dp[i+1][nj] = (dp[i+1][nj] + dp[i][j]) % MOD;
                }
            }
        }
    }
    rep(i,(1 << m)){
        ans = (ans+MOD-dp[n][i]) % MOD;
    }
    cout << ans << "\n";
    return 0;
}