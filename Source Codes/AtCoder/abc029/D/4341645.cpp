#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
#define all(c) begin(c),end(c)

template<typename T1, typename T2>
inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }

template<typename T1, typename T2>
inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

//??
typedef long long int ll;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0 //???????1????
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007


//????????
class Solve {
public:
    string s;
    ll dp[1001][2][101];

    void input() {
        cin >> s;
        memset(dp, -1, sizeof(dp));
//        for (int i = 0; i < 1001; ++i) {
//            for (int j = 0; j < 2; ++j) {
//                dp[i][j] = -1;
//            }
//        }

    }


    //n : ?????, ???
    //sum : ?????????
    ll rec(int n = 0, bool tight = true, int cnt = 0) {
        if (dp[n][tight][cnt] != -1) return dp[n][tight][cnt];
        if (n == s.size()) {
            return (s[n] == '1') + cnt;
        }

        int x = s[n] - '0';
        int lim = tight ? x : 9;

        ll ret = 0ll;
        for (int i = 0; i <= lim; ++i) {
            ret += rec(n + 1, tight && i == lim, cnt + (i == 1));
        }
        return dp[n][tight][cnt] = ret;
    }

    void solve() {
        input();
        ll ans = rec();

        cout << ans << endl;

    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    Solve().solve();


    return 0;
}