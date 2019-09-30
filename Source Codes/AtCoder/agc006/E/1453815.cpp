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

bool solve(int n, vector<array<int, 3> > const & a) {
    // parse
    vector<pair<int, bool> > b(n);
    repeat (x, n) {
        auto col = a[x];
        bool swapped = false;
        if (col[0] > col[2]) {
            swap(col[0], col[2]);
            swapped = true;
        }
        if (col[0] + 1 != col[1] or col[1] + 1 != col[2]) return false;
        if ((col[1] - 2) % 3 != 0) return false;
        int i = (col[1] - 2) / 3;
        if (i % 2 != x % 2) return false;
        b[x] = { i, not swapped };
    }
    if (n == 3) {
        return b[0].second == b[1].second and b[1].second == b[2].second;
    }
    assert (n >= 4);
    // sort
    {
        vector<int> c(n);
        repeat (x, n) {
            c[x] = b[x].first * 2 + b[x].second;
        }
        repeat (r, n) {
            int col = c[r];
            int l = r;
            while (l - 2 >= 0 and c[l - 2] > col) {
                c[l] = c[l - 2];
                l -= 2;
            }
            if (l < r) {
                c[l] = col;
                if ((r - l) / 2 % 2 == 1) {
                    c[l] ^= 1;
                }
                repeat_from (x, l + 1, r + 1) {
                    c[x] ^= 1;
                }
            }
        }
        repeat (x, n) {
            b[x] = { c[x] / 2, bool(c[x] % 2) };
        }
    }
/*
    repeat (r, n) {
        auto col = b[r];
        int l = r;
        while (l - 2 >= 0 and b[l - 2].first > col.first) {
            col.second ^= true;
            b[l - 1].second ^= true;
            b[l - 2].second ^= true;
            b[l] = b[l - 2];
            l -= 2;
        }
        if (l < r) {
            b[l] = col;
// fprintf(stderr, "swap:\n");
// repeat (x, n) fprintf(stderr, "%c", b[x].second ? '+' : '-'); fprintf(stderr, "\n"); repeat (x, n) fprintf(stderr, "%d", b[x].first); fprintf(stderr, "\n");
        }
    }
*/
    // normalize
    if (not b[0].second) {
        repeat (x, 4) b[x].second ^= true;
    }
    if (not b[n - 1].second) {
        repeat (x, 4) b[n - 1 - x].second ^= true;
    }
    repeat (x, n - 4) {
        if (not b[x + 1].second) {
            b[x + 1].second ^= true;
            b[x + 3].second ^= true;
        }
    }
    repeat (x, n) {
        if (not b[x].second) return false;
    }
    return true;
}

int main() {
    int n; scanf("%d", &n);
    vector<array<int, 3> > a(n);
    repeat (y, 3) {
        repeat (x, n) {
            scanf("%d", &a[x][y]);
        }
    }
    bool result = solve(n, a);
    printf("%s\n", result ? "Yes" : "No");
    return 0;
}