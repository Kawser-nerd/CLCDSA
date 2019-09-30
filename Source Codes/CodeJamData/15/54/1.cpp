
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
typedef pair<LL, LL> PII;
typedef vector<LL> VI;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.X << ", " << pair.Y << ")";}

map<LL,LL> doit(map<LL,LL> M, LL delta);
vector<LL> go(map<LL,LL> const &M) {
    vector<LL> tmp;
    FORE(it, M) {
        if (SZ(tmp) >= 2) break;
        tmp.PB(it->X);
        if (it->Y > 1) tmp.PB(it->X);
    }
    if (SZ(tmp) == 1) return vector<LL>();
    LL delta = tmp[1] - tmp[0];
    map<LL,LL> N = doit(M,delta);
    vector<LL> res = go(N);
    res.PB(delta);
    return res;
}

map<LL,LL> doit(map<LL,LL> M, LL delta) {
    map<LL,LL> N;
    FORE(it, M) {
        if (it->Y == 0) continue;
        if (delta == 0) {
            N[it->X] = it->Y/2;
        } else {
            M[it->X+delta] -= it->Y;
            N[it->X] = it->Y;
        }
    }
    return N;
}
void tr(map<LL,LL> const &M, vector<LL> &v, int i) {
    if (i == SZ(v)) return;
    LL delta = v[i];
    map<LL,LL> N = doit(M, delta);
    if (N[0] == 0) {
        map<LL,LL> tmp;
        FORE(it, N) tmp[it->X+delta] = it->Y;
        N = tmp;
        v[i] *= -1;
    }
    tr(N, v, i+1);

}

void solve(int tc) {
    cout << "Case #" << tc << ": ";
    int p;
    map<LL,LL> M;
    cin >> p;
    vector<PII> A(p);
    REP(i,p) cin >> A[i].X;
    REP(i,p) cin >> A[i].Y;
    REP(i,p) M[-A[i].X] = A[i].Y;
    vector<LL> V = go(M);
    tr(M,V,0);
    FORE(it, V) *it *= -1;
    sort(ALL(V));
    FORE(it, V) cout << *it << " ";
    cout << endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int T;
    cin >> T;
    REP(i,T) solve(i+1);


    return 0;
}

