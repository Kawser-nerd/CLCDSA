#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <vector>
#define repeat(i, n) for (int i = 0; (i) < int(n); ++(i))
using namespace std;

int median(int a, int b, int c) {
    if (a > b) swap(a, b);
    return max(a, min(b, c));
}

template <typename UnaryPredicate>
int binsearch(int l, int r, UnaryPredicate p) { // [l, r), p is monotone
    assert (l < r);
    -- l;
    while (r - l > 1) {
        int m = (l + r) / 2;
        (p(m) ? r : l) = m;
    }
    return r; // = min { x in [l, r) | p(x) }, or r
}

int main() {
    // input
    int n; scanf("%d", &n);
    vector<int> a(2 * n - 1);
    repeat (x, 2 * n - 1) {
        scanf("%d", &a[x]);
    }
    // solve
    if ((n - 1) % 2 == 1) {
        vector<int> b(2 * n - 3);
        repeat (x, 2 * n - 3) {
            b[x] = median(a[x], a[x + 1], a[x + 2]);
        }
        a.swap(b);
        -- n;
    }
    int result = binsearch(1, 2 * n, [&](int limit) {
        vector<char> b(2 * n - 1);
        repeat (x, 2 * n - 1) {
            b[x] = a[x] > limit;
        }
        int result = b[n - 1];
        int dist = 2 * n;
        repeat (x, (2 * n - 1) - 2) {
            if ((b[x] != b[x + 1] and b[x + 1] == b[x + 2])
                    or (b[x] == b[x + 1] and b[x + 1] != b[x + 2])) {
                int ndist = abs((x + 1) - (n - 1));
                if (ndist < dist) {
                    dist = ndist;
                    result = b[x + 1];
                }
            }
        }
        return not result;
    });
    // output
    printf("%d\n", result);
    return 0;
}