
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

const LD eps = 1e-18;

LD doit(LD V, LD t, const vector<pair<LD,LD> > &S) {
    LD temp = 0;
    FORE(it, S) {
        LD tme = min(t,V/it->Y);
        V -= tme*it->Y;
        temp += tme*it->Y*it->X;
    }
    assert(V < eps);
    return temp;
}

void solve(int tc) {
    cout << fixed << setprecision(10);
    cout << "Case #" << tc << ": ";
    int n; LD V, T;
    cin >> n >> V >> T;
    vector<pair<LD,LD> > S(n);
    LD mn = 1;
    LD sum = 0;
    REP(i,n) {
        cin >> S[i].Y >> S[i].X;
        mini(mn, S[i].Y);
        sum += S[i].Y;
    }
    sort(ALL(S));
    if (T < S[0].X || T > S[n-1].X) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    LD tb = V/sum, te = 10*V/mn;
    REP(_, 1000) {
        LD t = (tb+te)/2;
        LD tmin = doit(V, t, S)/V;
        reverse(ALL(S));
        LD tmax = doit(V,t,S)/V;
        reverse(ALL(S));
        if (tmin - eps < T && T < tmax+eps) te = t;
        else tb = t;
    }
    assert(tb < 2* V/mn);
    cout << tb << endl;

}


int main(){
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int T;
    cin >> T;
    REP(i,T) solve(i+1);


    return 0;
}

