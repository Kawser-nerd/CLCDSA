#include <cstdio>
#include <cstdlib>
#include <vector>
#define repeat(i, n) for (int i = 0; (i) < int(n); ++(i))
#define repeat_reverse(i, n) for (int i = (n)-1; (i) >= 0; --(i))
using namespace std;

int main() {
    // input
    int n, dd; scanf("%d%d", &n, &dd);
    vector<int> d(n); repeat (i, n) scanf("%d", &d[i]);

    // solve
    vector<int> a(n + 1);
    a[0] = dd;
    repeat (i, n) {
        a[i + 1] = min(a[i], abs(a[i] - d[i]));
    }
    vector<int> b(n + 1);
    b[n] = 1;
    repeat_reverse (i, n) {
        b[i] = b[i + 1] + (b[i + 1] <= d[i] / 2 ? 0 : d[i]);
    }

    // output
    int queries; scanf("%d", &queries);
    while (queries --) {
        int q_i; scanf("%d", &q_i); -- q_i;
        bool result = b[q_i + 1] <= a[q_i];
        printf("%s\n", result ? "YES" : "NO");
    }
    return 0;
}