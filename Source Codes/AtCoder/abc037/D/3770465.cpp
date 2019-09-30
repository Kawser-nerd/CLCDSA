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
    int H, W;
    vector<vector<int>> a;
    vector<vector<ll>> tapi;

    void input() {
        cin >> H >> W;
        a.resize(H + 2, vector<int>(W + 2, INF));
        tapi.resize(H + 2, vector<ll>(W + 2, 0ll));
        for (int i = 0; i < H + 2; ++i) {
            tapi[i][0] = tapi[i][W + 1] = -1;
        }
        for (int i = 0; i < W + 2; ++i) {
            tapi[0][i] = tapi[H + 1][i] = -1;
        }
        for (int i = 1; i <= H; ++i) {
            for (int j = 1; j <= W; ++j) {
                cin >> a[i][j];
            }
        }
    }

    ll rec(int h, int w) {
        if (tapi[h][w] == -1) return 0;
        if (tapi[h][w]) return tapi[h][w];
        int dh[] = {-1, 0, 1, 0};
        int dw[] = {0, -1, 0, 1};
        ll ret = 1ll;
        for (int k = 0; k < 4; ++k) {
            if (a[h][w] > a[h + dh[k]][w + dw[k]])
                (ret += rec(h + dh[k], w + dw[k])) %= MOD;
        }
        return tapi[h][w] = ret;
    }

    void solve() {
        input();
        ll ans = 0ll;
        for(int i = 1; i <= H; ++i){
            for(int j = 1; j <= W; ++j){
                (ans += rec(i,j)) %= MOD;
            }
        }
        cout << ans << endl;

    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Solve().solve();


    return 0;
}