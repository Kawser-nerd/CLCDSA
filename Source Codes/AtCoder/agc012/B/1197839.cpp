#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
using namespace std;

#define rep(i,a,n) for(int (i)=(a); (i)<(n); (i)++)
#define repq(i,a,n) for(int (i)=(a); (i)<=(n); (i)++)
#define repr(i,a,n) for(int (i)=(a); (i)>=(n); (i)--)
#define all(v) begin(v), end(v)
#define pb(a) push_back(a)
#define fr first
#define sc second
#define INF 2000000000
#define int long long int

#define X real()
#define Y imag()
#define EPS (1e-10)
#define EQ(a,b) (abs((a) - (b)) < EPS)
#define EQV(a,b) ( EQ((a).X, (b).X) && EQ((a).Y, (b).Y) )
#define LE(n, m) ((n) < (m) + EPS)
#define LEQ(n, m) ((n) <= (m) + EPS)
#define GE(n, m) ((n) + EPS > (m))
#define GEQ(n, m) ((n) + EPS >= (m))

typedef vector<int> VI;
typedef vector<VI> MAT;
typedef pair<int, int> pii;
typedef long long ll;

typedef complex<double> P;
typedef pair<P, P> L;
typedef pair<P, double> C;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};
int const MOD = 1000000007;
ll mod_pow(ll x, ll n) {return (!n)?1:(mod_pow((x*x)%MOD,n/2)*((n&1)?x:1))%MOD;}
int madd(int a, int b) {return (a + b) % MOD;}
int msub(int a, int b) {return (a - b + MOD) % MOD;}
int mmul(int a, int b) {return (a * b) % MOD;}
int minv(int a) {return mod_pow(a, MOD-2);}
int mdiv(int a, int b) {return mmul(a, minv(b));}

namespace std {
    bool operator<(const P& a, const P& b) {
        return a.X != b.X ? a.X < b.X : a.Y < b.Y;
    }
}

typedef vector< vector<int> > Graph;

Graph G;
int N, M, Q;
int color[100010];
int rec[100010];
void dfs(int point, int col, int cur, int par = -1) {
    if(rec[point] >= cur) return;
    if(color[point] == 0) color[point] = col;
    rec[point] = cur;
    if(cur == 0) return;
    rep(i,0,G[point].size()) {
        int to = G[point][i];
        if(to == par) continue;
        dfs(to, col, cur-1, point);
    }
}

struct query {
    int v, d, c;
};

signed main() {
    cin >> N >> M;
    G.resize(N);
    rep(i,0,M) {
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    memset(color, 0, sizeof(color));
    memset(rec, -1, sizeof(rec));

    cin >> Q;
    vector<query> qs(Q);
    rep(i,0,Q) {
        cin >> qs[i].v >> qs[i].d >> qs[i].c;
        qs[i].v--;
    }
    reverse(qs.begin(), qs.end());

    rep(i,0,Q) {
        dfs(qs[i].v, qs[i].c, qs[i].d);
    }

    rep(i,0,N) {
        cout << color[i] << endl;
    }
    return 0;
}