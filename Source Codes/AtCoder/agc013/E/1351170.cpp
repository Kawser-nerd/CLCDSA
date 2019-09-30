#include <cstdio>
#include <vector>
#define repeat(i, n) for (int i = 0; (i) < int(n); ++(i))
using ll = long long;
using namespace std;

constexpr int mod = 1e9+7;
int main() {
    // input
    int n, m; scanf("%d%d", &n, &m);
    vector<int> x(m+1); repeat (i, m) scanf("%d", &x[i]);
    // solve
    ll result = 1;
    ll preserved = 0;
    ll delta = 0;
    ll acc = 0;
    int j = 0;
    int x_j = x[j];
    repeat (i, n) {
        acc += result;
        preserved += 2 * delta + acc;
        delta += acc;
        if (i % 17 == 0) {
            preserved %= mod;
            delta %= mod;
            acc %= mod;
        }
        result = preserved;
        if (x_j == i+1) {
            result = 0;
            x_j = x[++ j];
        }
    }
    // output
    printf("%lld\n", result % mod);
    return 0;
}