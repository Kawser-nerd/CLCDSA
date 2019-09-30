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
#define MAXN 21

LD prob[1<<MAXN], res;

int main(){
	ios_base::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
    int T;
    cin >> T;
    FOR(t,1,T) {
	    //in
        string s;
        cin >> s;
        int n = SZ(s);
        int beg = 0;
        REP(i,n) if(s[i] == 'X') beg |= (1 << i);
	    //sol
        CLR(prob);
        res = 0;
        prob[beg] = 1;
        FOR(mask,beg,(1<<n)-2) {
 //           cout << mask << " " << prob[mask] << endl;
            LD p = prob[mask] / n;
            REP(j,n) {
                int poz = j, pay = n;
                while(mask&(1<<poz)) {
                    poz = (poz+1)%n;
                    pay--;
                }
                prob[mask|(1<<poz)] += p;
                res += p * pay;
            }
        }
	    //out
//        debug(prob[(1<<n)-1]);
        cout << "Case #" << t << ": " << res << endl;
    }
	return 0;
}

