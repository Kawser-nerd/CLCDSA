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
int N;
int X, Y, Z;
int S;


int next(int prev, int k) {
    int mask = (1 << S) - 1;
    int ret = ((prev << k) + (1 << (k - 1))) & mask;
    return ret;
}

bool check(int bit) {
//    return !(bit >> (S - 1));
    int top = (X + Y + Z) - 1;
    int mid = (Y + Z) - 1;
    int bot = Z - 1;
    return !(
            ((bit >> top) & 1) &&
            ((bit >> mid) & 1) &&
            ((bit >> bot) & 1)
    );
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> X >> Y >> Z;
    S = X + Y + Z;

    vector<vector<ll> > dp(N + 1, vector<ll>(1 << S));
    dp[0][0] = 1;

    for (int i = 0; i < N; ++i) {
        for (int bit = 0; bit < 1 << S; ++bit) {
            if (check(bit)) {
                for (int k = 1; k <= 10; ++k) {
                    if (check(next(bit, k))) {
                        ll &tmp = dp[i + 1][next(bit, k)];
                        tmp = (tmp + dp[i][bit]) % MOD;
//                        dp[i + 1][next(bit,k)] += dp[i][bit];
                        int a = 0;

                    } else {
                        //?????(????????)
                    }
                }
            }
        }
    }

//    ll ans = 0;
//
//    for (int bit = 0; bit < 1 << S; ++bit) {
//        ans = (ans + dp[N - 1][bit]) % MOD;
//    }

    ll ans = 1ll;
    for (int i = 0; i < N; ++i) {
        ans = ans * 10ll % MOD;
    }

    for (int bit = 0; bit < 1 << S; ++bit) {
        ans = (ans - dp[N][bit]) % MOD;
        if (ans < 0) ans += MOD;
    }

    cout << ans << endl;


    return 0;
}