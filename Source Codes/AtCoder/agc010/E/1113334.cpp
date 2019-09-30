#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#define repeat(i,n) for (int i = 0; (i) < int(n); ++(i))
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
using ll = long long;
using namespace std;
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;
int gcd(int a, int b) { while (a) { b %= a; swap(a, b); } return b; }
bool is_swappable(int a, int b) { return gcd(a, b) == 1; }
int main() {
    // input
    int n; cin >> n;
    vector<int> a(n); repeat (i,n) cin >> a[i];
    // rearrange
    whole(sort, a);
    vector<int> b;
    vector<bool> used(n);
    function<void (int)> go = [&](int i) {
        used[i] = true;
        b.push_back(a[i]);
        repeat (j,n) if (not used[j] and not is_swappable(a[i], a[j])) {
            go(j);
        }
    };
    repeat (i,n) if (not used[i]) {
        go(i);
    }
    // insertion sort
    repeat (i,n) {
        int j = i;
        for (int k = i-1; k >= 0 and is_swappable(b[k], b[i]); -- k) {
            if (b[k] < b[i]) j = k;
        }
        rotate(b.begin() + j, b.begin() + i, b.begin() + i + 1);
    }
    // output
    for (auto it : b) cout << it << ' '; cout << endl;
    return 0;
}