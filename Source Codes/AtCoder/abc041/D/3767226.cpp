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
    int M;
    vector<set<int> > prev;//?????????


    void input() {
        cin >> N >> M;
        prev.resize(N + 1);
        rep(i, 0, M) {
            int x, y;
            cin >> x >> y;
            prev[x].insert(y);
        }
    }

    void solve() {
        input();

        vector<vector<ll> > dp(N + 1, vector<ll>(1 << (N + 1)));
        dp[0][0] = 1ll;

        for (int i = 0; i < N; ++i) {
            for (int bit = 0; bit < 1ll << (N + 1); ++bit) {
                set<int> used;
                for (int j = 0; j < N + 1; ++j) {
                    if ((bit >> j) & 1) {
                        used.insert(j);
                    }
                }
                for (int j = 1; j < N + 1; ++j) {
                    if (!((bit >> j) & 1)) {
                        bool ok = true;
                        for (auto e : used) {
                            if(prev[j].count(e))
                                ok = false;
//                            for (auto f : prev[j]) {
//                                if (e == f)
//                                    ok = false;
//                            }
                        }
                        //??
                        //j???
                        if (ok) {
                            (dp[i + 1][bit | (1 << j)] += dp[i][bit]);
                        }
                    }
                }

            }
        }

        ll ans = 0ll;
        for (auto e : dp[N]) {
            (ans += e);
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