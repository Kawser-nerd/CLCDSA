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
    int N;
    vector<vector<int> > treeone;
    vector<vector<ll> > dp;

    void input() {
        cin >> N;
        treeone.resize(N);
        dp.resize(N, vector<ll>(2, -1));
        rep(i, 0, N - 1) {
            int a, b;
            cin >> a >> b;
            --a, --b;
            treeone[a].push_back(b);
            treeone[b].push_back(a);
        }
    }

    ll rec(int v, int c, int p) {
        if (p != -1 && treeone[v].size() == 1) {
            return 1ll;
        }
        if (dp[v][c] != -1) return dp[v][c];

        if (c == 0) {
            ll ret = 1ll;
            for (auto nv : treeone[v]) {
                if (nv != p) {
                    ll tmp = (rec(nv, 0, v) + rec(nv, 1, v)) % MOD;
                    (ret *= tmp) %= MOD;
                }
            }
            return dp[v][c] = ret;
        } else {
            ll ret = 1ll;
            for (auto nv : treeone[v]) {
                if (nv != p) {
                    ll tmp = rec(nv, 0, v);
                    (ret *= tmp) %= MOD;
                }
            }
            return dp[v][c] = ret;
        }
    }


    void solve() {
        input();
        ll ans = (rec(0, 0, -1) + rec(0, 1, -1)) % MOD;
        cout << ans << endl;

    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Solve().solve();


    return 0;
}