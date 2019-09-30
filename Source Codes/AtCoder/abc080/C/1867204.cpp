#include <array>
#include <climits>
#include <cstdio>
#include <vector>
#define repeat(i, n) for (int i = 0; (i) < int(n); ++(i))
#define repeat_from(i, m, n) for (int i = (m); (i) < int(n); ++(i))
using namespace std;
template <class T> inline void setmax(T & a, T const & b) { a = max(a, b); }

int main() {
    // input
    int n; scanf("%d", &n);
    vector<array<int, 10> > f(n);
    repeat (i, n) repeat (j, 10) scanf("%d", &f[i][j]);
    vector<array<int, 11> > p(n);
    repeat (i, n) repeat (j, 11) scanf("%d", &p[i][j]);
    // solve
    int result = INT_MIN;
    repeat_from (s, 1, 1 << 10) {
        int acc = 0;
        repeat (i, n) {
            int conflict = 0;
            repeat (j, 10) if (s & (1 << j)) {
                conflict += f[i][j];
            }
            acc += p[i][conflict];
        }
        setmax(result, acc);
    }
    // output
    printf("%d\n", result);
    return 0;
}