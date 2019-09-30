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
#define MAXN 100007

LL X,Y;

int main(){
	ios_base::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
    int T;
    cin >> T;
    FOR(t,1,T) {
	    //in
        cin >> X >> Y;
	    //sol
        LL r = 0, sum = 0;
        LL cel = abs(X) + abs(Y);
        while(sum < cel || sum%2 != cel%2) {
            r++;
            sum += r;
        }
        string res;
        FORD(i,r,1) {
            if(abs(X) > abs(Y)) {
                if(X > 0) res += 'E', X -= i;
                else res += 'W', X += i;
            } else {
                if(Y > 0) res += 'N', Y -= i;
                else res += 'S', Y += i;
            }
        }
        assert(X == 0 || Y == 0);
        reverse(ALL(res));
	    //out
        cout << "Case #" << t << ": " << res << endl;
    }
	return 0;
}

