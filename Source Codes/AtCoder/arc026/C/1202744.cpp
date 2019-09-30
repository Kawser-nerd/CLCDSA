#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;
using ll = long long;
#define int ll
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define RFOR(i, a, b) for (int i = (b)-1; i >= int(a); --i)
#define rep(i, n) FOR(i, 0, n)
#define rep1(i, n) FOR(i, 1, int(n) + 1)
#define rrep(i, n) RFOR(i, 0, n)
#define rrep1(i, n) RFOR(i, 1, int(n) + 1)
#define all(c) begin(c), end(c)
const int MOD = 1000000007;

template <typename T>
void __dump__(std::ostream &os, const T &first) {
    os << first;
}
template <typename First, typename... Rest>
void __dump__(std::ostream &os, const First &first, const Rest &... rest) {
    os << first << ", ";
    __dump__(os, rest...);
}
#define dump(...)                                         \
    do {                                                  \
        std::ostringstream os;                            \
        os << __LINE__ << ":\t" << #__VA_ARGS__ << " = "; \
        __dump__(os, __VA_ARGS__);                        \
        std::cerr << os.str() << std::endl;               \
    } while (0)

const int INF = 1e18;
const int B = 512;

constexpr int CEIL(int n) {
    while (n % B) ++n;
    return n;
}

const int MAX_N = CEIL(100001);
int a[MAX_N];
int b[MAX_N / B + 1];

tuple<int,int,int> q[100010];

int N, L;

void set_(int k, int x) {
    a[k] = x;
    b[k/B] = INF;
    for (int i = 0; i < B; ++i) {
        b[k/B] = min(a[k - k%B + i], b[k/B]);
    }
}

int get(int k) {
    return a[k];
}

int get_min(int l, int r) {
    int res = INF;
    if (l/B == r/B) {
        for (int i = l; i < r; ++i) {
            res = min(res, a[i]);
        }
    } else {
        for (int i = l; i < l + B - l%B; ++i) {
            res = min(res, a[i]);
        }
        for (int i = r - r%B; i < r; ++i) {
            res = min(res, a[i]);
        }
        for (int i = l/B + 1; i < r/B; ++i) {
            res = min(res, b[i]);
        }
    }
    return res;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    while (cin >> N >> L) {
        rep(i, N) {
            int l, r, c;
            cin >> l >> r >> c;
            q[i] = make_tuple(l, r, c);
        }
        sort(q, q + N);
        fill(all(a), INF);
        fill(all(b), INF);
        set_(0, 0);
        rep(i, N){
            int l, r, c;
            tie(l, r, c) = q[i];
            int cand = get_min(l, r) + c;
            // dump(l, r, get_min(l, r));
            set_(r, min(get(r), cand));

            // rep(i, L+1) {
            //     cout << get(i) << ' ';
            // }
            // cout << endl;
        }
        cout << get(L) << endl;
    }
}