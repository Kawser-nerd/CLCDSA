#include <cstdio>
#include <vector>
#include <algorithm>
#include <array>
#include <set>
#include <map>
#include <queue>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <cassert>
#define repeat(i, n) for (int i = 0; (i) < int(n); ++(i))
#define repeat_from(i, m, n) for (int i = (m); (i) < int(n); ++(i))
#define repeat_reverse(i, n) for (int i = (n)-1; (i) >= 0; --(i))
#define repeat_from_reverse(i, m, n) for (int i = (n)-1; (i) >= int(m); --(i))
#define whole(f, x, ...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
#define unittest_name_helper(counter) unittest_ ## counter
#define unittest_name(counter) unittest_name_helper(counter)
#define unittest __attribute__((constructor)) void unittest_name(__COUNTER__) ()
using ll = long long;
using namespace std;
template <class T> inline void setmax(T & a, T const & b) { a = max(a, b); }
template <class T> inline void setmin(T & a, T const & b) { a = min(a, b); }
template <typename X, typename T> auto vectors(X x, T a) { return vector<T>(x, a); }
template <typename X, typename Y, typename Z, typename... Zs> auto vectors(X x, Y y, Z z, Zs... zs) { auto cont = vectors(y, z, zs...); return vector<decltype(cont)>(x, cont); }

template <typename UnaryPredicate>
ll binsearch(ll l, ll r, UnaryPredicate p) { // [l, r), p is monotone
    assert (l < r);
    -- l;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        (p(m) ? r : l) = m;
    }
    return r; // = min { x in [l, r) | p(x) }, or r
}

ll decrease_destructive(vector<ll> & a) {
    int n = a.size();
    ll result = 0;
    while (true) {
        bool modified = false;
        ll acc_k = 0;
        repeat (i, n) if (a[i] >= n) {
            ll k = a[i] / n;
            a[i] %= n;
            a[i] -= k;
            acc_k += k;
            result += k;
            modified = true;
        }
        repeat (j, n) a[j] += acc_k;
        if (not modified) break;
    }
    return result;
}
ll decrease(vector<ll> a) {
    return decrease_destructive(a);
}

constexpr ll max_a = 10000000000000000ll + 1000ll;
int main() {
    ll k; scanf("%lld", &k);
    int n = 2;
    while (decrease(vector<ll>(n, max_a)) < k) ++ n;
    vector<ll> a(n);
    repeat (i, n) {
        a[i] = max_a - 500;
        if (decrease(a) > k) {
            a[i] = 0;
            vector<ll> b = a;
            ll base = decrease_destructive(b);
            a[i] = binsearch(0, max_a - 500 + 1, [&](ll a_i) {
                vector<ll> c = b;
                c[i] += a_i;
                return base + decrease_destructive(c) >= k;
            });
            while (decrease(a) < k and a[i] < max_a - 500) {
                ll delta = decrease(a) - k;
                a[i] = min(max_a, a[i] - 500 + delta);
            }
        }
        if (decrease(a) >= k) break;
    }
    assert (decrease(a) >= k);
    ll delta = decrease(a) - k;
    while (delta --) {
        int i = whole(max_element, a) - a.begin();
        a[i] -= n;
        repeat (j, n) if (j != i) a[j] += 1;
    }
    assert (decrease(a) == k);
    assert (not a.empty());
    printf("%d\n", n);
    repeat (i, n) {
        printf("%lld%c", a[i], i + 1 == n ? '\n' : ' ');
        assert (a[i] <= max_a);
    }
    return 0;
}