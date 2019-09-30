
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

vector<int> generate(int n) {
    LL v0, a,c,r;
    cin >> v0 >> a >> c >> r;
    vector<int> res(n);
    res[0] = v0;
    FOR(i, 1, n-1) {
        res[i] = (res[i-1]*a+c)%r;
    }
    return res;

}
vector<int> S,M;
vector<PII> be;
vector<vector<int> > chld;

void go(int i, int b, int e) {
    mini(b, S[i]);
    maxi(e, S[i]);
    be[i] = MP(b,e);
    for (int j : chld[i]) go(j,b,e);
}

void solve(int tc) {
    cout << "Case #" << tc << ": ";
    int n,d;
    cin >> n >> d;
    S = generate(n);
    M = generate(n);
    chld = vector<VI>(n);
    FOR(i,1,n-1) {
        chld[M[i]%i].PB(i);
    }
    be = vector<PII>(n);
    go(0, S[0], S[0]);
    vector<pair<LL,int> > ev;
    REP(i,n) {
        if (be[i].Y > be[i].X + d) continue;
        ev.PB(MP(be[i].Y-d, -1));
        ev.PB(MP(be[i].X, 1));
    }
    sort(ALL(ev));
    LL res = 0;
    LL cnt = 0;
    for (pair<LL,int> e : ev) {
        cnt -= e.Y;
        maxi(res, cnt);
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

