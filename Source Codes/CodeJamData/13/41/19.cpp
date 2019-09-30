

#include<algorithm>
#include<cassert>
#include<complex>
#include<map>
#include<iomanip>
#include<sstream>
#include<queue>
#include<set>
#include<string>
#include<cstdio>
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
#define DEBUG 1
#define debug(x) {if (DEBUG)cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FORE(it, (x)) cerr <<*it <<", "; cout <<endl; }}
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int, int>P;
typedef vector<int>VI;
const int INF=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
#define MAXN 1000007
LL M = 1000002013;

int solve() {
    LL n,m;
    cin >> n >> m;
    LL val = 0;
    vector<P> ev;
    REP(i, m) {
        LL x,y,p;
        cin >> x >> y >> p;
        LL d = y-x;
        val = (val + p*((d*n - d*(d-1)/2)%M))%M;
        ev.PB(MP(x, -p));
        ev.PB(MP(y,p));
    }
    LL mn = 0;
    sort(ALL(ev));
    map<LL, LL> inside;
    FORE(it, ev) {
        if (it->Y < 0) { //enter
            LL p = -it->Y;
            inside[-it->X] += p;
        } else {
            LL p = it->Y;
            while(p > 0) {
                VAR(mt, inside.begin());
                LL cr, d;
                d = it->X + mt->X;
                if (mt->Y <= p) {
                    p -= mt->Y;
                    cr = mt->Y;
                    inside.erase(mt);
                } else {
                    cr = p;
                    mt->Y -= p;
                    p = 0;
                }
                mn = (mn + cr*((d*n-d*(d-1)/2)%M))%M;
            }
        }
    }
    assert(inside.empty());
    cout << (val - mn+M) % M << endl;

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    REP(i,t) {
        cout << "Case #" << (i+1) << ": ";
        solve();
    }
    return 0;
}

