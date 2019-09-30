#include <cstdio>
#include <vector>
#include <algorithm>
#define repeat(i,n) for (int i = 0; (i) < int(n); ++(i))
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
using ll = long long;
using namespace std;
constexpr int mod = 1e9+7;
int main() {
    int w, h; scanf("%d%d", &w, &h);
    vector<int> x(w); repeat (i,w) scanf("%d", &x[i]);
    vector<int> y(h); repeat (i,h) scanf("%d", &y[i]);
    whole(sort, x);
    whole(sort, y);
    ll x_acc = 0;
    repeat (j,w) x_acc += x[j] *(ll) j;
    repeat (i,w) x_acc -= x[i] *(ll) (w-i-1);
    ll y_acc = 0;
    repeat (j,h) y_acc += y[j] *(ll) j;
    repeat (i,h) y_acc -= y[i] *(ll) (h-i-1);
    int result = (x_acc % mod) * (y_acc % mod) % mod;
    printf("%d\n", result);
    return 0;
}