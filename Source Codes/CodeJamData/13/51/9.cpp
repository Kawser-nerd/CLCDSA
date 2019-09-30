#include<algorithm>
#include<cassert>
#include<complex>
#include<map>
#include<iomanip>
#include<sstream>
#include<queue>
#include<set>
#include<string>
#include<vector>
#include<iostream>
#include<cstring>
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define fup FOR
#define fdo FORD
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define siz SZ
#define CLR(x) memset((x), 0, sizeof(x))
#define PB push_back
#define MP make_pair
#define X first
#define Y second 
#define FI X
#define SE Y
#define SQR(a) ((a)*(a))
#define DEBUG 1
#define debug(x) {if (DEBUG)cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FORE(it, (x)) cerr <<*it <<", "; cout <<endl; }}
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int, int>P;
typedef vector<int>VI;
const int INF=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
#define MAXN 37

LD sol(vector<LL> v, LL B) {
    LL BB = B;
    if(B <= 0) return 0;
    LL low = 0, high = v.back() - 1;
    if(high <= 0) return 0;
    while(low < high) {
        LL mid = (low + high + 1) / 2;
        LL need = 0;
        REP(i,MAXN) need += max(0LL, mid - v[i]);
        if(B >= need)
            low = mid;
        else
            high = mid - 1;
    }
    REP(i,MAXN) B -= max(0LL, low - v[i]);
    LL sum = 0;
    LL n = 0;
    FORD(i,MAXN-1,0) {
        if(v[i] <= low) {
            if(v[i] == v[0] || B == 0) {
            sum += low - v[i];
            n++;
            } else B--;
        }
    }
    LD res =  ((LD)sum / n) * 36.0 - (BB - B);
//    cout << low << " BB " << BB << " B " << B << " res " << res << endl;
    return res;
}

int main(){
	ios_base::sync_with_stdio(false);
    cout << setprecision(9) << fixed;
    int T;
    cin >> T;
    FOR(t,1,T) {
	    //in
        LL B,N;
        cin >> B >> N;
        vector<LL> v;
        while(N--) {
            LL x;
            cin >> x;
            v.PB(x);
        }
        while(SZ(v) < MAXN) v.PB(0);
	    //sol
        sort(ALL(v));
        LD res = 0;
        FOR(i,0,100) maxi(res, sol(v, B-i));
	    //out
        cout << "Case #" << t << ": " << res << endl;
    }
	return 0;
}

