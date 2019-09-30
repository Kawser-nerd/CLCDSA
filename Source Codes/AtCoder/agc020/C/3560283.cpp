#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <array>
#include <bitset>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

struct BitVec {
    static constexpr size_t B = 64;
    size_t n;
    V<ull> d;
    explicit BitVec(size_t _n = 0) : n(_n), d((n + B - 1) / B) {}
    size_t size() const { return n; }
    bool operator[](size_t i) const { return ((d[i / B] >> (i % B)) & 1) != 0; }
    void set(size_t i, bool f) {
        if (f)
            d[i / B] |= (1ULL << (i % B));
        else
            d[i / B] &= ~(1ULL << (i % B));
    }
    void reset() { fill(d.begin(), d.end(), 0); }
    void push_back(bool f) {
        if (n % B == 0) d.push_back(0);
        set(n, f);
        n++;
    }

    void swap_elms(size_t a, size_t b) {
        bool f = (*this)[a];
        set(a, (*this)[b]);
        set(b, f);
    }

    template <class OP> BitVec& op1(OP op) {
        for (auto& x : d) x = op(x);
        return *this;
    }

    template <class OP> BitVec& op2(const BitVec& r, OP op) {
        assert(n == r.n);
        for (size_t i = 0; i < d.size(); i++) d[i] = op(d[i], r.d[i]);
        return *this;
    }

    BitVec& operator&=(const BitVec& r) { return op2(r, bit_and<ull>()); }
    BitVec& operator|=(const BitVec& r) { return op2(r, bit_or<ull>()); }
    BitVec& operator^=(const BitVec& r) { return op2(r, bit_xor<ull>()); }
    BitVec& operator<<=(const size_t& s) {
        auto block = s / B, rem = s % B;
        if (d.size() <= block) {
            reset();
            return *this;
        }
        for (size_t i = d.size() - 1; i > block; i--) {
            if (rem == 0)
                d[i] = d[i - block];
            else {
                d[i] = (d[i - block] << rem) | ((d[i - block - 1]) >> (B - rem));
            }
        }
        d[block] = d[0] << rem;
        fill(d.begin(), d.begin() + block, 0);
        return *this;
    }
    BitVec& operator>>=(const size_t& s) {
        //don't work
        auto block = s / B, rem = s % B;
        if (d.size() <= block) {
            reset();
            return *this;
        }
        for (size_t i = 0; i < d.size() - block; i++) {
            if (rem == 0)
                d[i] = d[i + block];
            else {
                ull u = (d[i + block] << rem);
                if (i + block + 1 < d.size())
                    u |= (d[i + block + 1]) >> (B - rem);
                d[i] = u;
            }
        }
        d[d.size() - block - 1] = (d[d.size() - 1] << rem);
        for (size_t i = d.size() - block; i < d.size(); i++) d[i] = 0;
        return *this;
    }
    BitVec operator&(const BitVec& r) const { return BitVec(*this) &= r; }
    BitVec operator|(const BitVec& r) const { return BitVec(*this) |= r; }
    BitVec operator^(const BitVec& r) const { return BitVec(*this) ^= r; }
    BitVec operator<<(const size_t& s) const { return BitVec(*this) <<= s; }
    BitVec operator>>(const size_t& s) const { return BitVec(*this) >>= s; }
};

const int MD = 2000 * 2000 + 100;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    int n;
    cin >> n;
    V<int> a(n);
    int sm = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sm += a[i];
    }

    BitVec bs(sm + 1);
    bs.set(0, true);
    for (int d: a) {
        bs |= bs << d;
    }

    for (int i = (sm+1)/2; i <= sm; i++) {
        if (!bs[i]) continue;
        cout << i << endl;
        return 0;
    }
    assert(false);
    return 0;
}