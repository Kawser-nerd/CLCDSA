#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define repeat(i,n) for (int i = 0; (i) < int(n); ++(i))
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
using ll = long long;
using namespace std;
int gcd(int a, int b) { while (a) { b %= a; swap(a, b); } return b; }
bool solve(int n, vector<int> & a) {
    ll sum = whole(accumulate, a, 0ll);
    bool is_first = (sum - n) % 2;
    int even = whole(count_if, a, [&](int ai) { return ai % 2 == 0; });
    auto odd = whole(find_if,  a, [&](int ai) { return ai % 2 == 1; });
    if (not is_first and even == n-1 and *odd != 1) {
        -- (*odd);
        int d = a[0]; repeat (i,n) d = gcd(d, a[i]);
        repeat (i,n) a[i] /= d;
        return not solve(n, a);
    } else {
        return is_first;
    }
}
int main() {
    int n; cin >> n;
    vector<int> a(n); repeat (i,n) cin >> a[i];
    cout << (solve(n, a) ? "First" : "Second") << endl;
    return 0;
}