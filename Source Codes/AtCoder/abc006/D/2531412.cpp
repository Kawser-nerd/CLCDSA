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
//#define EACH(i, c) for (auto &(i): c)
#define all(c) begin(c),end(c)
//#define EXIST(s, e) ((s).find(e)!=(s).end())
//#define SORT(c) sort(begin(c),end(c))
//#define pb emplace_back
//#define MP make_pair
//#define SZ(a) int((a).size())

//#define LOCAL 0
//#ifdef LOCAL
//#define DEBUG(s) cout << (s) << endl
//#define dump(x)  cerr << #x << " = " << (x) << endl
//#define BR cout << endl;
//#else
//#define DEBUG(s) do{}while(0)
//#define dump(x) do{}while(0)
//#define BR
//#endif


//??
typedef long long int ll;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0 //???????1????
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007

//????????
template<typename T, typename E>
struct SegmentTree {
    using F = function<T(T, T)>;
    using G = function<T(T, E)>;
    using H = function<E(E, E)>;
    using P = function<E(E, size_t)>;
    int n;
    F f; //?????????
    G g; //?????????
    H h; //???????????
    T ti; //???????
    E ei; //????????
    P p; //b?????a????????
    vector<T> dat;
    vector<E> laz;

    SegmentTree(int n_, F f, G g, H h, T ti, E ei,
                P p = [](E a, size_t b) {
                    b++;
                    return a;
                }) :
            f(f), g(g), h(h), ti(ti), ei(ei), p(p) {
        init(n_);
    }

    void init(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        dat.assign(2 * n - 1, ti);
        laz.assign(2 * n - 1, ei);
    }

    void build(int n_, vector<T> v) {
        for (int i = 0; i < n_; i++) dat[i + n - 1] = v[i];
        for (int i = n - 2; i >= 0; i--)
            dat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);
    }

    inline void eval(int len, int k) {
        if (laz[k] == ei) return;
        if (k * 2 + 1 < n * 2 - 1) {
            laz[k * 2 + 1] = h(laz[k * 2 + 1], laz[k]);
            laz[k * 2 + 2] = h(laz[k * 2 + 2], laz[k]);
        }
        dat[k] = g(dat[k], p(laz[k], len));
        laz[k] = ei;
    }

    T update(int a, int b, E x, int k, int l, int r) {
        eval(r - l, k);
        if (r <= a || b <= l) return dat[k];
        if (a <= l && r <= b) {
            laz[k] = h(laz[k], x);
            return g(dat[k], p(laz[k], r - l));
        }
        return dat[k] = f(update(a, b, x, k * 2 + 1, l, (l + r) / 2),
                          update(a, b, x, k * 2 + 2, (l + r) / 2, r));
    }

    T update(int a, int b, E x) {
        return update(a, b, x, 0, 0, n);
    }

    T query(int a, int b, int k, int l, int r) {
        eval(r - l, k);
        if (r <= a || b <= l) return ti;
        if (a <= l && r <= b) return dat[k];
        T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return f(vl, vr);
    }

    T query(int a, int b) {
        return query(a, b, 0, 0, n);
    }

    /**
     * k?x?????
     */
    void update(int k, T x) {
        query(k, k + 1);//evaluate
        k += n - 1;
        dat[k] = x;
        while (k) {
            k = (k - 1) / 2;
            dat[k] = f(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> c(N + 2);
    vector<int> rc(N + 2);
    vector<bool> used(N + 2);
    int p = 0;
    int q = 0;
    int ans = 0;
    rep(i, 0, N) cin >> c[i + 1];
    c[N + 1] = N + 1;

    vector<int> dp(N + 2);
    dp[0] = 1;
    int max_dp = 1;
    for(int i = 1; i <= N + 1; i++){
        for(int j = 0; j < i; j++){
            if(c[j] < c[i]){
                dp[i] = max(dp[i],dp[j] + 1);
            }
        }
        max_dp = max(max_dp,dp[i]);
    }
    ans = N + 2 - max_dp;


    cout << ans << endl;


    return 0;
}