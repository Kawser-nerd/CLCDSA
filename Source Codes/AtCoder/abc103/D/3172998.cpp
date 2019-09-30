#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> ab(m);
    for (int i = 0; i < m; i++) cin >> ab[i].first >> ab[i].second;
    sort(ab.rbegin(), ab.rend());

    int div_point = 0, ans = 0;
    for (int i = 0; i < m; i++) {
        if (ab[i].first <= div_point && div_point < ab[i].second) {
            continue;
        } else {
            div_point = ab[i].first;
            ans++;
        }
    }

    cout << ans << endl;
}