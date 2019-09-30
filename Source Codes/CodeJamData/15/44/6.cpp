
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
typedef vector<LL> VI;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.X << ", " << pair.Y << ")";}

const LL P = 1e9+7;
void add(LL &x, LL y, LL z = 1) {
    x = (x+z*y) % P;
}
LL pot(LL x, LL n) {
    LL res = 1;
    while(n) {
        if (n&1) res = (res*x) % P;
        x = (x*x) % P;
        n /= 2;
    }
    return res;

}
LL rev(LL x) {
    return pot(x, P-2);
}
void solve(int tc) {
    cout << "Case #" << tc << ": ";
    int r,c;
    cin >> r >> c;
    vector<VI> A(r+5, VI(8,0)), B(r+5, VI(8,0));
    A[0][0] = B[0][0] = 1;
    int gcd[8] = {1, 3, 4, 12, 6, 6, 12, 12};
    REP(h, r) {
        REP(msk, 8) {
            // plain
            add(A[h+2][msk], B[h][msk]);
            add(B[h+1][msk], A[h][msk]);
            // mod 3
            if (c%3 == 0) add(B[h+2][msk|1], A[h][msk],3);
            if (c%4 == 0) add(B[h+3][msk|2], A[h][msk],4);
            // mod 6
            if (c%6 == 0) add(B[h+2][msk|4], A[h][msk],6);
        }
    }
    LL res = 0;
    REP(msk, 8) {
        add(res, A[r][msk]+B[r][msk], rev(gcd[msk]));
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

