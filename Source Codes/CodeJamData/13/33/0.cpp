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
typedef pair<P, int>PP;
typedef vector<int>VI;
const int INF=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
#define MAXN 1000007

#define BASE (1<<22)

struct DP {
    int dp[2*BASE],whole[2*BASE];
    void clear(){CLR(dp); CLR(whole);}

    void set(int l, int r, int v, int x = 1, int ll = 1, int rr = BASE) {
//        if(x == 1) cout << "set " << l << "-" << r << " " << v << endl;
        if(r < ll || rr < l) return;
        if(l <= ll && rr <= r) { //przedzial basowy
            maxi(whole[x], v);
            maxi(dp[x], v);
//            cout << "set" << " " << x << " " << v << endl;
        } else { //nadprzedzial
            set(l, r, v, x+x, ll, (ll+rr)/2);
            set(l, r, v, x+x+1, (ll+rr+1)/2, rr);
            //update
            dp[x] = max(min(dp[x+x], dp[x+x+1]), whole[x]);
        }
    }

    int get(int l, int r, int x = 1, int ll = 1, int rr = BASE) {
//        if(x == 1) cout << "get " << l << "-" << r << endl;
        if(r < ll || rr < l) return INF;
        if(l <= ll && rr <= r) { //przedzial basowy
///            cout << "get " << x << " " << dp[x] << "     " << ll << " " << rr << endl;
            return dp[x];
        } else { //nadprzedzial
            return max(min(
            get(l, r, x+x, ll, (ll+rr)/2),
            get(l, r, x+x+1, (ll+rr+1)/2, rr)), whole[x]);
        }
    }

};

DP dpp;
int N;
int d[MAXN],n[MAXN],w[MAXN],e[MAXN],s[MAXN],dd[MAXN],dp[MAXN],ds[MAXN];
vector<PP> atak[MAXN];
VI wsp;

int tran(int x){
    return lower_bound(ALL(wsp), x) - wsp.begin() + 1;
}

int main(){
	ios_base::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
    int T;
    cin >> T;
    FOR(t,1,T) {
	    //in
        dpp.clear();
        cin >> N;
        REP(i,N) cin >> d[i] >> n[i] >> w[i] >> e[i] >> s[i] >> dd[i] >> dp[i] >> ds[i];
        //tran
        wsp.clear();
        REP(i,N) REP(j,n[i]) {
            wsp.PB(w[i] + j * dp[i]);
            wsp.PB(e[i] + j * dp[i]);
            wsp.PB(w[i] + j * dp[i] - 1);
            wsp.PB(e[i] + j * dp[i] - 1);
        }
        sort(ALL(wsp));
        wsp.erase(unique(ALL(wsp)),wsp.end());
	    //sol
        REP(i,MAXN) atak[i].clear();
        REP(i,N) REP(j,n[i]) {
            int x1 = w[i] + j * dp[i];
            int x2 = e[i] + j * dp[i] - 1;
            if(x1 <= x2)
            atak[d[i] + j * dd[i]].PB(PP(P(tran(x1), tran(x2)), s[i] + j * ds[i]));
        }
        LL res = 0;
        REP(i,MAXN) {
            FORE(j,atak[i]) res += dpp.get(j->X.X, j->X.Y) < j->Y;
            FORE(j,atak[i]) dpp.set(j->X.X, j->X.Y, j->Y);
//            if(!atak[i].empty()) cout << res << endl;
        }
	    //out
        cout << "Case #" << t << ": " << res << endl;
    }
	return 0;
}

