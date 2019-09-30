#include <iostream>
#include <vector>
#define repeat(i,n) for (int i = 0; (i) < (n); ++(i))
using namespace std;
const int inf = 1e9+7;
int main() {
    int n, t; cin >> n >> t;
    vector<int> a(n); repeat (i,n) cin >> a[i];
    vector<int> minacc(n+1); minacc[0] = inf; repeat (i,n) minacc[i+1] = min(minacc[i], a[i]);
    auto profit = [&](int i) { return a[i] - minacc[i+1]; };
    int max_profit = -1, cnt = 0;
    repeat (i,n) {
        if (max_profit < profit(i)) {
            max_profit = profit(i);
            cnt = 1;
        } else if (max_profit == profit(i)) {
            cnt += 1;
        }
    }
    cout << cnt << endl;
    return 0;
}