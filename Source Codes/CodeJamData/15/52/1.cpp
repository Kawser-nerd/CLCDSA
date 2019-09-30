
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
typedef vector<int> VI;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.X << ", " << pair.Y << ")";}


void solve(int tc) {
    cout << "Case #" << tc << ": ";
    int n,k;
    cin >> n >> k;
    vector<LL> S(n-k+1);
    REP(i,n-k+1) cin >> S[i];
    vector<LL> delta(k,0);
    vector<PII> va(k, MP(0,0));
    REP(i, n-k) {
        int j = i%k;
        delta[j] += S[i+1] - S[i];
        maxi(va[j].X, -delta[j]);
        maxi(va[j].Y, delta[j]);
    }
    LL res = 0;
    REP(i, k) maxi(res, va[i].X+va[i].Y);
    LL sum = 0, slack = 0;
    REP(i,k) {
        sum += va[i].X;
        slack += res - (va[i].X+va[i].Y);
    }
    while((S[0]-sum) % k != 0) {
        --slack;
        ++sum;
    }
    if (slack < 0) ++res;
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

