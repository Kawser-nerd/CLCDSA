#include<algorithm>
#include<cassert>
#include<complex>
#include<map>
#include<iomanip>
#include<sstream>
#include<queue>
#include<set>
#include<string>
#include<cstdio>
#include<vector>
#include<iostream>
#include<cstring>
#include<stack>
#include<bitset>
#include<unordered_map>
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define CLR(x) memset((x), 0, sizeof(x))
#define PB push_back
#define MP make_pair
#define X first
#define Y second 
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
template<typename T1, typename T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { out << "(" << pair.FI << ", " << pair.SE << ")"; return out; }
#define MAXN 50007

int T,n,a[MAXN];
int mi[MAXN],ma[MAXN];

LD sol(LD rytm) {
    LD res = 0.0;
    FOR(i,1,n-1) {
        maxi(res, abs(ma[i] -  rytm*i));
        maxi(res, abs(mi[i] -  rytm*i));
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin >> T;
    FOR(cas,1,T) {
        REP(i,MAXN) mi[i] = INF, ma[i] = -INF;
        //in
        cin >> n;
        FOR(i,1,n) cin >> a[i];
        //sol
        FOR(i,1,n) FOR(j,i+1,n) {
            mini(mi[j-i], a[j]-a[i]);
            maxi(ma[j-i], a[j]-a[i]);
        }
        LD low = 0.0, high = 1E7;
        REP(_,200) {
            LD l = low + 0.3 * (high - low);
            LD r = low + 0.7 * (high - low);
            if(sol(l) < sol(r))
                high = r;
            else
                low = l;
        }
        //out
        cout << "Case #" << cas << ": ";
        cout << sol(low)/2 << endl;
    }
    return 0;
}

