
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

typedef LL TYP;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.X << ", " << pair.Y << ")";}

typedef complex<TYP> P;
typedef pair<P, P> PP;
inline TYP operator^(P a, P b) { return real(a) * imag(b) - imag(a) * real(b); }//iloczyn wektorowy
inline TYP operator%(P a, P b) { return real(a) * real(b) + imag(a) * imag(b); }//iloczyn skalarny
P vec = P(1, 0);
P vecp = vec * P(0, 1);
int dir = 1;
// dir = 1 <=> clock-wise
int cw(const P& w) {
    TYP a, b;
    a = vec ^ w, b = vecp ^ w;
    if ((dir == 1 && a <= 0) || (dir == -1 && a >= 0)) 
        return (b <= 0 ? 0 : 1);
    return (b >= 0 ? 2 : 3);
}
bool angle_comp(P l, P r) {
    int cl = cw(l), cr = cw(r);
    if (cl != cr) return cl < cr;
    TYP w = l ^ r;
    return (dir == 1 ? w < 0: w > 0);
}

P apply(P cur, P a) {
    return P(max(cur.real()+a.real(), 0ll), max(cur.imag()+a.imag(),0ll));
}

void solve(int tc) {
    cout << "Case #" << tc << ": ";
    int N,m;
    cin >> N >> m;
    assert(m <= 2);
    vector<P> V[2];
    int res = 0;
    REP(i,N) {
        int a,b;
        cin >> a;
        if (m == 2) cin >> b;
        else b = 0;
        if (a <= 0 && b <= 0) {}
        else if (a >= 0 && b >= 0) res += a+b;
        else if (a < 0) V[0].PB(P(a,b)); 
        else if (b < 0) V[1].PB(P(a,b)); 
        else assert(false);
    }
    dir = 1;
    sort(ALL(V[0]), angle_comp);
    dir = -1;
    sort(ALL(V[1]), angle_comp);
    LL ans = 0;
  //  debugv(V[0]);
  //  debugv(V[1]);
    REP(x,2) {
    int n[2];
    n[0] = SZ(V[0]);
    n[1] = SZ(V[1]);
    REP(t, n[0]+1) {
        P cur(0,0);
        REP(i,t) cur = apply(cur, V[0][i]);
        REP(i,n[1]) cur = apply(cur,V[1][i]);
        FOR(i,t,n[0]-1) cur = apply(cur, V[0][i]);
        maxi(ans, res+cur.real()+cur.imag());
    }
    swap(V[0], V[1]);
    }
    cout << ans << endl; 
}


int main(){
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int T;
    cin >> T;
    REP(i,T) solve(i+1);
    return 0;
}

