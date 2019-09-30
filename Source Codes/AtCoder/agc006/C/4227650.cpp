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
    void input() {

    }

    vector<int> mul(vector<int> f, vector<int> g) {
        int n = f.size();
        vector<int> ret(n);
        rep(i, 0, n) {
            ret[i] = g[f[i]];
        }
        return ret;
    }


    void solve() {
        input();
        int N;
        cin >> N;
        vector<ll> x(N);
        rep(i, 0, N) cin >> x[i];

        int M;
        ll K;
        cin >> M >> K;
        vector<int> a(M);
        rep(i, 0, M) {
            cin >> a[i];
        }

        vector<int> base(N - 1);
        rep(i, 0, N - 1) base[i] = i;
        vector<int> f = base;

        for (int i = 0; i < M; ++i) {
            swap(base[a[i] - 2], base[a[i] - 1]);
        }


        ll rest = K;
        while (rest > 0) {
            if (rest & 1) f = mul(f, base);
            base = mul(base, base);
            rest >>= 1;
        }

        vector<ll> d(N - 1);
        vector<ll> neko(N - 1);
        for (int i = 0; i < N - 1; ++i) {
            d[i] = x[i + 1] - x[i];
        }
        for (int i = 0; i < N - 1; ++i) {
            neko[i] = d[f[i]];
        }
        vector<ll> ans(N);
        ans[0] = x[0];
        for (int i = 1; i < N; ++i) {
            ans[i] = ans[i - 1] + neko[i - 1];
        }

        for (int i = 0; i < N; ++i) {
            cout << ans[i] << endl;
        }


        return;

    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    Solve().solve();


    return 0;
}