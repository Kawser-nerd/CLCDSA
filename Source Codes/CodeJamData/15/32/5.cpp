
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

void solve(int tc) {
    cout << fixed << setprecision(10);
    cout << "Case #" << tc << ": ";
    int k,l,s;
    cin >> k >> l >> s;
    string K,L;
    cin >> K >> L;
    REP(i, l) {
        bool ok = false;
        REP(j,k) if (L[i] == K[j]) ok = true;
        if (!ok) {
            cout << LD(0) << endl;
            return;
        }
    }
    int p = 1;
    for (;p <= l; ++p) {
        bool ok = true;
        REP(i,l-p) if (L[i] != L[i+p]) ok = false;
        if (ok) break;
    }
    int ban = 1+(s-l)/p;
    vector<VI> state(l+1,VI(k,0));
    REP(i, l+1) REP(j,k) {
        string cur = L.substr(0,i)+K.substr(j,1);
        while(true) {
            if (cur.length() <= l && cur == L.substr(0, cur.length())) break;
            cur = cur.substr(1);
        }
        state[i][j] = cur.length();
    } 
    //REP(i,l+1) debugv(state[i]);
    vector<LD> prv(0,l+1), nxt(l+1,0);
    nxt[0] = 1;
    LD res = 0;
    REP(t, s) {
        prv = nxt;
        nxt = vector<LD>(l+1, 0);
        REP(i,l+1) REP(j,k) nxt[state[i][j]] += prv[i]/k;
        res += nxt[l];
    }
    cout << ban-res << endl;


}


int main(){
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int T;
    cin >> T;
    REP(i,T) solve(i+1);


    return 0;
}

