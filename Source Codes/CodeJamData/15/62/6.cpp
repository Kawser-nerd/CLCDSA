
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

const LL P = 1e9+7;

LL pw(LL a, int n) {
    LL res = 1;
    while(n) {
        if (n & 1) res = (res * a) % P;
        a = (a * a) % P;
        n /= 2;
    }
    return res;
}

LL rev(LL a) {
    return pw(a,P-2);
}
const int MX = 1e6+10;
LL fac[MX];
LL np[MX];

void solve(int tc) {
    cout << "Case #" << tc << ": ";
    LL n,k;
    cin >> n >> k;
    LL res = 0;
    for (LL x = k; x <= n; ++x) {
        LL cur = np[n-x]*rev(fac[x]);
        res = (res + cur) % P;
    }
    res = ((res * fac[n])% P);
    res = ((res * fac[n])% P);
    cout << res << endl;

}


int main(){
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int T;
    cin >> T;
    fac[0] = 1;
    FOR(i,1,MX-1) fac[i] = (fac[i-1]*i)%P;
    np[0] = 1;
    FOR(i,1,MX-1) np[i] = (np[i-1]+P+rev(fac[i])*((i%2)?(-1):1))%P;


    REP(i,T) solve(i+1);
    return 0;
}

