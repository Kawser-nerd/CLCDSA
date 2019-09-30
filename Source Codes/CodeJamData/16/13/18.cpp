#include<cstdio>
#include<cstring>
#include<cassert>
#include<vector>
#include<list>
#include<queue>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<typeinfo>
#include<locale>
#include<iterator>
#include<valarray>
#include<complex>
#include<climits>

using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         acos(-1.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

vector < int > vc[1001];
int to[1001], vis[1001], tt[1001];
int go(int c){
    int ret = 1;
    REP(i, vc[c].size()){
        if(vc[c][i] == to[c]) continue;
        ret = max(ret, 1 + go(vc[c][i]));
    }
    return ret;
}

int res2;
void dfs(int c, int v, int t){
    vis[c] = v;
    tt[c] = t;

    if(vis[to[c]] == 0) dfs(to[c], v, t + 1);
    else if(vis[to[c]] == v){
        res2 = max(res2, t - tt[to[c]] + 1);
    }
}


int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    FOR(ts, 1, T+1){
        int n; cin >> n;
        FOR(i, 1, n+1) {
            vc[i].clear();
        }
        FOR(i, 1, n+1){
            cin >> to[i];
            vc[to[i]].pb(i);
        }

        int res1 = 0;
        FOR(i, 1, n+1){
            if(to[to[i]] == i){
                res1 += go(i) + go(to[i]);
            }
        }
        res1 /= 2;

        set0(vis);

        res2 = 0;
        int cc = 0;
        FOR(i, 1, n+1){
            if(vis[i] == 0){
                dfs(i, ++cc, 1);
            }
        }

        cout << "Case #" << ts << ": " << max(res1, res2) << endl;
    }
}
