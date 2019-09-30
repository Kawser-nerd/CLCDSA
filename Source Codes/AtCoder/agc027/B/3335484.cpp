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

ll N, X;
vector<ll> x;

ll simulate(ll n) {
    //n????????????????????????
    ll ret = X * n + X * N;

    for (ll i = 0; i < N; ++i) {
        ll mul = max(5ll, 2 * (i / n) + 3);
        ll index = N - i - 1;
        ret += x[index] * mul;
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> X;
    x.resize(N);
    rep(i, 0, N) cin >> x[i];

//    cout << simulate(1) << endl;

    ll lb = 1;
    ll ub = N + 1;
    ll ans;

//    if (true) {
//        for (int i = 1; i <= N; ++i) {
//            cout << simulate(i) << endl;
//        }
//    }

    while (true) {
        ll sec1 = lb + (ub - lb) / 3;
        ll sec2 = lb + 2 * (ub - lb) / 3;

        ll val1 = simulate(sec1);
        ll val2 = simulate(sec2);
        if (ub - lb <= 3) {
//            ans = min(val1, val2);
//            ans = min(all(vector<ll>({val1, val2})));
            ans = val1;
            for (ll t = lb; t <= ub; ++t) {
                if (t == 0) continue;
                chmin(ans, simulate(t));
            }
            break;
        }
        if (val1 < val2) {
            ub = sec2;
        } else {
            lb = sec1;
        }
    }

    cout << ans << endl;


    return 0;
}