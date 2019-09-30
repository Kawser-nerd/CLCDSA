#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[i] = make_pair(a, b - 1);
    }
    sort(v.begin(), v.end());
    int ans = 1;
    int low = -1;
    int high = 1000000;
    for (int i = 0; i < m; i++) {
        if (v[i].first <= high) {
            low = max(low, v[i].first);
            high = min(high, v[i].second);
        } else {
            ans++;
            low = v[i].first;
            high = v[i].second;
        }
    }
    cout << ans << endl;
}