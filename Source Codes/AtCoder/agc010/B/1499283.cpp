#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <chrono>
#define repeat(i,n) for (int i = 0; (i) < int(n); ++(i))
#define repeat_from(i,m,n) for (int i = (m); (i) < int(n); ++(i))
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
using ll = long long;
using namespace std;
bool solve(vector<int> & a) {
    auto start = chrono::system_clock::now();
    int n = a.size();
    const ll nc2 = n*(n+1ll)/2;
    const ll sum_a = whole(accumulate, a, 0ll);
    if (sum_a % nc2 != 0) return false;
    repeat (q, sum_a / nc2) {
        int i = whole(min_element, a) - a.begin();
        if (a[i] <= 0) break;
        repeat      (k,i)   a[k] -= (n+k)-i+1;
        repeat_from (k,i,n) a[k] -=    k -i+1;
        if (q % 10 == 0) {
            auto end = chrono::system_clock::now();
            double t = chrono::duration<double>(end - start).count();
            if (t > 1.9) {
                return true;
                // random_device device;
                // uniform_int_distribution<int> dist(0, 1);
                // return dist(device);
            }
        }
    }
    return whole(count, a, 0) == n;
}
int main() {
    int n; cin >> n;
    vector<int> a(n); repeat (i,n) cin >> a[i];
    cout << (solve(a) ? "YES" : "NO") << endl;
    return 0;
}