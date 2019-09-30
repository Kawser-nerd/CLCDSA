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

vector<double> memo_f;
vector<double> memo_g;

double f(ll N) {
    if (memo_f[N] != -1) return memo_f[N];
    if (N == 2) return memo_f[N] = 1.0;
    return memo_f[N] = 1.0 * (N + 2) / N * f(N - 2) + 1.0;
}

double g(ll N) {
    if (memo_g[N] != -1) return memo_g[N];
    if (N == 2) return memo_g[N] = 0.5;
//    return memo_g[N] = 5.0 / N * f(N - 2) + 12.0 / N * g(N - 2) + (N - 1) / 2.0;
    return memo_g[N] = 5.0 / N * f(N - 2) + (N + 4.0) / N * g(N - 2) + (N - 1) / 2.0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, d, x;
    cin >> N >> d >> x;

    memo_f.resize(2 * N + 1, -1);
    memo_g.resize(2 * N + 1, -1);

    double ans = d * f(2 * N) + x * g(2 * N);
    cout << fixed << setprecision(9);

    cout << ans << endl;

    return 0;
}