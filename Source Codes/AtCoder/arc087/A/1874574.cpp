#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

using LL = long long;

int main() {
    cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    cout.setf(std::ios_base::fixed);
    cout.precision(24);
    // freopen("input.txt", "r+", stdin);
    int n, a;
    cin >> n;
    map < int, int > cnt;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        cnt[a]++;
    }
    int res = 0;
    for (auto p : cnt) {
        if (p.first == p.second) {
            continue;
        }
        if (p.second > p.first) {
            res += p.second - p.first;
        } else {
            res += p.second;
        }
    }
    cout << res;
    return 0;
}