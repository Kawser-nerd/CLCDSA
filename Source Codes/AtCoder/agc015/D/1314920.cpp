#include <cstdio>
#include <cassert>
#define repeat(i,n) for (int i = 0; (i) < int(n); ++(i))
#define repeat_reverse(i,n) for (int i = (n)-1; (i) >= 0; --(i))
using ll = long long;
using namespace std;

const int bit_size = 60;
int msb(ll x) {
    repeat_reverse (i, bit_size) {
        ll y = 1ll << i;
        if (y & x) return i;
    }
    return -1;
}
ll solve(ll a, ll b) {
    // drop unnecessarily bits
    while (true) {
        int r = msb(b);
        if (r == -1) break;
        ll x = 1ll << r;
        if ((a & x) and (b & x)) {
            a ^= x;
            b ^= x;
        } else {
            break;
        }
    }
    // trivial case
    if (b == 0) return 1;
    assert (a < b);
    // prepare
    int r = msb(b);
    ll x = 1ll << r;
    assert (     b & x);
    assert (not (a & x));
    ll result = 0;
    // the msb is true
    if (b == x) {
        if (a == 0) {
            result += x - a;
        } else {
            result += x - a + 1;
        }
    } else {
        int k = msb(b ^ x);
        assert (k != -1);
        if (a >= (1ll << (k+1))) {
            result += 1ll << (k+1);
            result += x - a;
        } else {
            result += x;
        }
    }
    // the msb is false
    result += x - a;
    return result;
}

int main() {
    ll a, b; scanf("%lld%lld", &a, &b);
    ll result = solve(a, b);
    printf("%lld\n", result);
    return 0;
}