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
#include <cstring>

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
    int A = 0;
    int G = 1;
    int C = 2;
    int T = 3;

    ll dp[101][4][4][4][4];

    void input() {
        memset(dp, 0, sizeof(dp));
        cin >> N;
    }

    bool check(int _3, int _2, int _1) {
        if (_3 == A && _2 == G && _1 == C) {
            return false;
        }
        if (_3 == G && _2 == A && _1 == C) {
            return false;
        }
        if (_3 == A && _2 == C && _1 == G) {
            return false;
        }

        return true;
    }

    bool check(int _4, int _3, int _2, int _1) {
        if (!check(_4, _3, _2) || !check(_3, _2, _1)) return false;
        if (_4 == A && _3 == G && _1 == C) return false;
        if (_4 == A && _2 == G && _1 == C) return false;
        return true;
    }


    void solve() {
        input();
        if (N == 1) {
            cout << 4 << endl;
            return;
        }
        if (N == 2) {
            cout << 16 << endl;
            return;
        }
        if (N == 3) {
            cout << 61 << endl;
            return;
        }
        if (N == 4) {
            cout << 230 << endl;
            return;
        }

        for (int _1 = 0; _1 < 4; ++_1) {
            for (int _2 = 0; _2 < 4; ++_2) {
                for (int _3 = 0; _3 < 4; ++_3) {
                    for (int _4 = 0; _4 < 4; ++_4) {
                        if (check(_1, _2, _3, _4)) dp[4][_1][_2][_3][_4] = 1;
                    }
                }
            }
        }

        for (int i = 5; i <= N; ++i) {
            for (int _1 = 0; _1 < 4; ++_1) {
                for (int _2 = 0; _2 < 4; ++_2) {
                    for (int _3 = 0; _3 < 4; ++_3) {
                        for (int _4 = 0; _4 < 4; ++_4) {
                            if (check(_1, _2, _3, _4)) {
                                for (int _5 = 0; _5 < 4; ++_5) {
                                    if (check(_2, _3, _4, _5)) {
                                        (dp[i][_2][_3][_4][_5] += dp[i-1][_1][_2][_3][_4]) %= MOD;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        ll ans = 0ll;
        for (int _1 = 0; _1 < 4; ++_1) {
            for (int _2 = 0; _2 < 4; ++_2) {
                for (int _3 = 0; _3 < 4; ++_3) {
                    for (int _4 = 0; _4 < 4; ++_4) {
                        (ans += dp[N][_1][_2][_3][_4]) %= MOD;
                    }
                }
            }
        }

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