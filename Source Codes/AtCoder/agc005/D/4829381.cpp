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
#define MOD 924844033
//#define MOD 100000000


//????????
class Solve {
public:
    int N, K;

    void input() {
        cin >> N >> K;
    }

    int v(int i) {
        if (N % K == 0) {
            return N / K;
        }
//        if (i < 2 * (1 + K - (N % K))) return (N - 1) / K + 1;
        if (i < 2 * (N % K)) return (N - N % K) / K + 1;
        return (N - N % K) / K;
    }

    vector<vector<ll>> alpha_v;

    ll alpha(int c, int d) {
        if (alpha_v.size() == 0) {
            alpha_v.resize(N + 1, vector<ll>(N + 1, -1));
        }
        if (d < 0) return 0;
        if (c < 1) return 0;
        if (c == 1) return d == 0;
        if (c == 2) return (d == 1 || d == 0);

        if (alpha_v[c][d] != -1) return alpha_v[c][d];


        ll ret = (alpha(c - 2, d - 1) + alpha(c - 1, d)) % MOD;
        return alpha_v[c][d] = ret;
    }

    vector<vector<ll>> mat;

    void mat_init() {
        mat.resize(2 * K + 1, vector<ll>(N + 1));
        mat[0][0] = 1ll;
        for (int i = 0; i < 2 * K; ++i) {
            for (int k = 0; k <= N; ++k) {
//                for (int d = 0; alpha(v(i), d) > 0; d++) {
                for (int d = 0;; d++) {
                    int c = v(i);
                    ll mul = alpha(c, d);
                    if (mul == 0) break;
                    (mat[i + 1][k + d] += (mul * mat[i][k])) %= MOD;
                }
            }
        }
    }

    vector<ll> fac;

    ll fact(int i) {
        if (fac.size() == 0) {
            fac.push_back(1);
            fac.push_back(1);
        }
        if (i < fac.size()) return fac[i];

        ll ret = 1ll * i * fact(i - 1) % MOD;
        fac.push_back(ret);
        return ret;
    }

    void solve() {
//        for (int i = 0; i < 10; ++i) {
//            cout << fact(10 + i) << endl;
//        }
        input();
        mat_init();

        ll ans = 0ll;
        for (int k = 0; k <= N; ++k) {
            ll tmp = mat[2 * K][k];
            tmp *= fact(N - k);
            tmp %= MOD;
            if (k % 2) tmp *= -1;
            ans += tmp;
            ans %= MOD;
            if (ans < 0) ans += MOD;
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