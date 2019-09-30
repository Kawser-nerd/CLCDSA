
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

const int MD = 200;
const int MX = 1e6+2;
int rgt[MD][MX];
int lft[MD][MX];



void solve(int tc) {
    cout << "Case #" << tc << ": ";
    int n;
    string S;
    cin >> S;
    n = SZ(S);
    REP(j,n+1)  {
        rgt[0][j] = j;
        lft[0][j] = j;
    }
    for (int c = 1; ; c++) {
        REP(j,n+1) {
            rgt[c][j] = rgt[c-1][j];
            lft[c][j] = lft[c-1][j];
        }
        REP(j, n) {
            int cc = c - S[j]+'0';
            if (cc < 0) continue;
            int l = lft[cc][j];
            int r = rgt[cc][j+1];
            mini(lft[c][r], l);
            maxi(rgt[c][l], r); 
        }

        FORD(j,n,1) mini(lft[c][j-1], lft[c][j]);
        REP(j,n) maxi(rgt[c][j+1], rgt[c][j]);

       // REP(j,n+1) cerr << MP(lft[c][j], rgt[c][j]) << " ";
       // cerr << endl;

        if (rgt[c][0] == n) {
            cout << c << endl;
            return;
        }
    }

}


int main(){
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int T;
    cin >> T;
    REP(i,T) solve(i+1);
    return 0;
}

