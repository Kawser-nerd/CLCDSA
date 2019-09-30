#include<algorithm>
#include<cassert>
#include<complex>
#include<map>
#include<iomanip>
#include<sstream>
#include<queue>
#include<set>
#include<string>
#include<vector>
#include<iostream>
#include<cstring>
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define fup FOR
#define fdo FORD
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define siz SZ
#define CLR(x) memset((x), 0, sizeof(x))
#define PB push_back
#define MP make_pair
#define X first
#define Y second 
#define FI X
#define SE Y
#define SQR(a) ((a)*(a))
#define DEBUG 0
#define debug(x) {if (DEBUG)cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FORE(it, (x)) cerr <<*it <<", "; cout <<endl; }}
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int, int>P;
typedef vector<int>VI;
const int INF=2E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
#define MAXN 2007

int n,m,p,path[MAXN],a[MAXN],b[MAXN],u[MAXN],v[MAXN],dis[MAXN],ogr[MAXN];
vector<P> G[MAXN];
bool small[MAXN];

inline int len(int x) {return small[x] ? a[x] : b[x];}

VI dist(int x, bool spec, int beg = 0) {
//    debug(x);
    FOR(i,1,n) dis[i] = INF;
    dis[x] = (spec ? beg : 0);
    priority_queue<P> Q;
    if(dis[x] <= ogr[x]) Q.push(P(-dis[x], x));
    while(!Q.empty()) {
        P pp = Q.top(); Q.pop();
        x = pp.Y;
        int k = -pp.X;
        if(dis[x] != k) continue;
        FORE(i,G[x]) {
            int kk = k + (spec ? a[i->Y] : len(i->Y));
            if(kk < dis[i->X] && (!spec || kk <= ogr[i->X])) {
                dis[i->X] = kk;
                Q.push(P(-kk, i->X));
            }
        }
    }
    VI res;
    res.PB(0);
    FOR(i,1,n) res.PB(dis[i]);
    return res;
}

bool test(int t) {
    CLR(small);
    FOR(i,1,t) small[path[i]] = true;
    VI bad = dist(1, false);
    FOR(i,1,n) ogr[i] = bad[i];
    int beg = 0;
    FOR(i,1,t) beg += a[path[i]];
    debug(t);
//    FOR(i,1,t) cout << a[i] << " -> "; cout << endl;
    debug(beg);
    VI good = dist(v[path[t]], true, beg);
    debugv(bad);
    debugv(good);
    return good[2] != INF;
}

int main(){
	ios_base::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
    int T;
    cin >> T;
    FOR(t,1,T) {
	    //in
        cin >> n >> m >> p;
        FOR(i,1,n) G[i].clear();
        FOR(i,1,m) {
            cin >> u[i] >> v[i] >> a[i] >> b[i];
            G[u[i]].PB(P(v[i],i));
        }
        FOR(i,1,p) cin >> path[i];
	    //sol
        int res = 0;
        FOR(i,1,p) if(!test(i)) {res = path[i]; break;}
	    //out
        cout << "Case #" << t << ": ";
        if(res == 0) cout << "Looks Good To Me";
        else cout << res;
        cout << endl;
    }
	return 0;
}

