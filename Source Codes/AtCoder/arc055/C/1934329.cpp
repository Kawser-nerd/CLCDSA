#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>
#define REP(i, n) for (int i = 0; (i) < int(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < int(n); ++ (i))
#define REP_R(i, n) for (int i = int(n) - 1; (i) >= 0; -- (i))
#define ALL(x) begin(x), end(x)
using ll = long long;
using namespace std;

template <class Monoid>
struct segment_tree {
    typedef typename Monoid::underlying_type underlying_type;
    int n;
    vector<underlying_type> a;
    const Monoid mon;
    segment_tree() = default;
    segment_tree(int a_n, underlying_type initial_value = Monoid().unit(), Monoid const & a_mon = Monoid()) : mon(a_mon) {
        n = 1; while (n < a_n) n *= 2;
        a.resize(2 * n - 1, mon.unit());
        fill(a.begin() + (n - 1), a.begin() + ((n - 1) + a_n), initial_value); // set initial values
        REP_R (i, n - 1) a[i] = mon.append(a[2 * i + 1], a[2 * i + 2]); // propagate initial values
    }
    void point_set(int i, underlying_type z) { // 0-based
        a[i + n - 1] = z;
        for (i = (i + n) / 2; i > 0; i /= 2) { // 1-based
            a[i - 1] = mon.append(a[2 * i - 1], a[2 * i]);
        }
    }
    underlying_type range_concat(int l, int r) { // 0-based, [l, r)
        underlying_type lacc = mon.unit(), racc = mon.unit();
        for (l += n, r += n; l < r; l /= 2, r /= 2) { // 1-based loop, 2x faster than recursion
            if (l % 2 == 1) lacc = mon.append(lacc, a[(l ++) - 1]);
            if (r % 2 == 1) racc = mon.append(a[(-- r) - 1], racc);
        }
        return mon.append(lacc, racc);
    }
};

template <typename UnaryPredicate>
ll binsearch(ll l, ll r, UnaryPredicate p) {
    assert (l <= r);
    -- l;
    while (r - l > 1) {
        ll m = l + (r - l) / 2;  // avoid overflow
        (p(m) ? r : l) = m;
    }
    return r;
}

ll powmod(ll x, ll y, ll p) {
    assert (0 <= x and x < p);
    assert (0 <= y);
    ll z = 1;
    for (ll i = 1; i <= y; i <<= 1) {
        if (y & i) z = z * x % p;
        x = x * x % p;
    }
    return z;
}

class rolling_hash {
    static constexpr int size = 1;
    static const int32_t prime[size];
    static int32_t base[size];
    static struct base_initializer_t {
        base_initializer_t() {
            random_device device;
            default_random_engine gen(device());
            REP (i, size) {
                base[i] = uniform_int_distribution<int32_t>(256, prime[i] - 1)(gen);
            }
        }
    } base_initializer;
public:
    array<int32_t, size> data;
    rolling_hash() : data({}) {}
    rolling_hash(char c) {
        REP (i, size) data[i] = c;
    }
    void push_back(char c) {
        REP (i, size) {
            data[i] = (data[i] *(int64_t) base[i] + c) % prime[i];
        }
    }
    rolling_hash & operator += (rolling_hash const & other) {
        REP (i, size) {
            data[i] += other.data[i];
            if (data[i] >= prime[i]) data[i] -= prime[i];
        }
        return *this;
    }
    rolling_hash operator + (rolling_hash const & other) const {
        return rolling_hash(*this) += other;
    }
    rolling_hash & operator <<= (int width) {
        REP (i, size) {
            data[i] = data[i] *(int64_t) powmod(base[i], width, prime[i]) % prime[i];
        }
        return *this;
    }
    rolling_hash operator << (int width) const {
        return rolling_hash(*this) <<= width;
    }
    bool operator == (rolling_hash const & other) const {
        return equal(ALL(data), other.data.begin());
    }
    bool operator != (rolling_hash const & other) const {
        return not (*this == other);
    }
    friend ostream & operator << (ostream & out, rolling_hash const & that) {
        char buffer[8 * size + 1];
        REP (i, size) {
            sprintf(buffer + 8 * i, "%08x", that.data[i]);
        }
        return out << buffer;
    }
};
const int32_t rolling_hash::prime[size] = { 1000000027 }; // , 1000000033 }; // , 1000000087, 1000000093 };
int32_t rolling_hash::base[size];
rolling_hash::base_initializer_t rolling_hash::base_initializer;

struct rolling_hash_monoid {
    typedef struct { int length; rolling_hash hash; } underlying_type;
    static underlying_type from_char(char c) {
        return { 1, rolling_hash(c) };
    }
    underlying_type unit() const {
        return { 0, rolling_hash() };
    }
    underlying_type append(underlying_type a, underlying_type const & b) const {
        if (a.length == 0) return b;
        if (b.length == 0) return a;
        return { a.length + b.length, (a.hash <<= b.length) += b.hash };
    }
};

int main() {
    // input
    string s; cin >> s;
    // solve
    int n = s.length();
    segment_tree<rolling_hash_monoid> hash(n);
    REP (i, n) hash.point_set(i, rolling_hash_monoid::from_char(s[i]));
    ll result = 0;
    REP3 (abc, 3, s.length() - 1) {
        int ac = n - abc;
        int b = abc - ac;
        if (b <= 0) continue;
        int a = binsearch(1, ac, [&](int x) {
            return hash.range_concat(0, x).hash != hash.range_concat(abc, abc + x).hash;
        }) - 1;
        int c = binsearch(1, ac, [&](int x) {
            return hash.range_concat(abc - x, abc).hash != hash.range_concat(n - x, n).hash;
        }) - 1;
        if (a + c >= ac) {
            result += a + c - ac + 1;
        }
    }
    // output
    printf("%lld\n", result);
    return 0;
}