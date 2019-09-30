#include <iostream>
#include <vector>
#include <algorithm>
#define repeat(i,n) for (int i = 0; (i) < int(n); ++(i))
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
using ll = long long;
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n); repeat (i,n) cin >> a[i];
    whole(sort, a);
    ll acc = 0;
    int l = 0, r = 0;
    while (true) {
        if (r == l) {
            acc += a[l];
            ++ r;
        }
        while (r < n and a[r] <= 2*acc) {
            acc += a[r];
            ++ r;
        }
        if (r == n) break;
        ++ l;
    }
    cout << r - l << endl;
    return 0;
}