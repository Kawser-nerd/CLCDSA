#include <cstdio>
#include <cctype>
#include <cmath>
#include <vector>
#include <set>
#include <cassert>
#define repeat(i,n) for (int i = 0; (i) < int(n); ++(i))
#define repeat_from_reverse(i,m,n) for (int i = (n)-1; (i) >= int(m); --(i))
using ll = long long;
using namespace std;
template <class T> inline void setmax(T & a, T const & b) { a = max(a, b); }
template <class T> inline void setmin(T & a, T const & b) { a = min(a, b); }

int solve(vector<int> const & d) {
    int n = d.size();
    if (n == 1) return d[0];
    assert (n >= 2);
    vector<int> delta(n-1);
    repeat (i,n-1) {
        delta[i] = (d[i+1] - d[i] + 10) % 10;
    }
    int k1, k2; {
        set<int> set_delta(delta.begin(), delta.end());
        if (set_delta.size() == 1) return d[0]; // A = d_i, B = 0, X = 1
        if (set_delta.size() >= 3) return -1; // impossible
        k1 = *set_delta.begin();
        k2 = *(++ set_delta.begin());
        if (k1 == 0 and k2 == 9) {
            swap(k1, k2);
        } else if (k2 != k1 + 1) {
            return -1; // impossible
        }
    }
    vector<int> e(n); {
        int acc = 0;
        e[0] = d[0];
        repeat (i,n-1) {
            if (d[i+1] < d[i]) {
                acc += 1; // overflow
            } else if (d[i+1] == d[i] and k1 == 9 and k2 == 0) {
                acc += 1; // overflow with 10
            }
            e[i+1] = acc * 10 + d[i+1];
        }
    }
    long double min_b_float = 0;
    long double max_b_float = INFINITY;
    repeat (j,n) {
        repeat (i,j) {
            constexpr long double eps = 1e-18;
            setmin(max_b_float, ((e[j] + 1 - eps) - e[i]) /(long double) (j - i));
            setmax(min_b_float, (e[j] - (e[i] + 1 - eps)) /(long double) (j - i));
        }
    }
    ll base = 1;
    for (int x = 0; x < 16; ++ x, base *= 10) {
        ll max_b = floorl(max_b_float * base);
        repeat_from_reverse (b, max(0ll, max_b-3), max_b+4) {
            ll a = 0;
            repeat (i,n) {
                setmax(a, e[i] * base - b * i);
            }
            bool is_valid = true;
            repeat (i,n) {
                if (not (e[i] * base <= a + b * i and a + b * i < (e[i] + 1) * base)) {
                    is_valid = false;
                    break;
                }
            }
            if (is_valid) {
                return a;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> d;
    for (char c; scanf("%c", &c), isdigit(c); ) {
        d.push_back(c - '0');
    }
    int result = solve(d);
    printf("%d\n", result);
    return 0;
}