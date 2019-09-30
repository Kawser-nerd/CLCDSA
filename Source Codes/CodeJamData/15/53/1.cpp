
#include<algorithm>
#include<bitset>
#include<cassert>
#include<complex>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<vector>
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#define X first
#define Y second 
#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define dprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef vector<int> VI;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.X << ", " << pair.Y << ")";}

const LD INF = 1e100;
const int MX = 510;
LD dyn[MX][MX];
void solve(int tca) {
    cout << "Case #" << tca << ": ";
    LD y; int n;
    cin >> y >> n;
    vector<PII> q(n);
    REP(i,n) cin >> q[i].X;
    REP(i,n) cin >> q[i].Y;
    vector<PII> pos;
    vector<PII> neg;
    REP(i,n) {
        if (q[i].X < 0) {
            q[i].X *= -1;
            neg.PB(q[i]);
        } else {
            pos.PB(q[i]);
        }
    }
    sort(ALL(pos));
    sort(ALL(neg));
    int po = SZ(pos);
    int ne = SZ(neg);
    REP(i, po+1) REP(j,ne+1) dyn[i][j] = INF;
    dyn[0][0] = 0;
    LD res = INF;
    REP(i, po+1) REP(j, ne+1) {
        LD t = dyn[i][j];
        LD tr = t;
        FOR(k, i, po-1) {
            LD tc = (pos[k].X + t*y)/(y-pos[k].Y);
            maxi(tr, tc);
            mini(dyn[k+1][j], 2*tr-t);
            if (j == ne && k == po-1) mini(res, tr);
        }
        tr = t;
        FOR(k, j, ne-1) {
            LD tc = (neg[k].X + t*y)/(y-neg[k].Y);
            maxi(tr, tc);
            mini(dyn[i][k+1], 2*tr-t);
            if (i == po && k == ne-1) mini(res, tr);
        } 
    }
    cout << res << endl;


}


int main(){
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int T;
    cin >> T;
    REP(i,T) solve(i+1);


    return 0;
}

