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
    int H, W, K;
    ll dp[10][200];

    vector<ll> cnt;

    void input() {
        cin >> H >> W >> K;
        cnt.resize(W, -1);
    }

    ll calc_cnt(int n) {
        if (n < 1) return 1;
//        if (n < 3) return 2;
        if (cnt[n] != -1) return cnt[n];
        return cnt[n] = (calc_cnt(n - 1) + calc_cnt(n - 2)) % MOD;
    }

    void solve() {
        input();

        dp[1][0] = 1;
        for (int h = 0; h < H; ++h) {
            for (int i = 1; i <= W; ++i) {
                if (i != 1) {
                    dp[i - 1][h + 1] += (1ll * calc_cnt(i - 3) * calc_cnt(W - i - 1) % MOD) * dp[i][h];
                    dp[i - 1][h + 1] %= MOD;
                }
                if (i != W) {
                    dp[i + 1][h + 1] += (1ll * calc_cnt(i - 2) * calc_cnt(W - i - 2) % MOD) * dp[i][h];
                    dp[i + 1][h + 1] %= MOD;
                }
                dp[i][h + 1] += (1ll * calc_cnt(i - 2) * calc_cnt(W - i - 1) % MOD) * dp[i][h];
                dp[i][h + 1] %= MOD;
            }
        }

        ll ans = dp[K][H];
        cout << ans << endl;


    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Solve().solve();


    return 0;
}