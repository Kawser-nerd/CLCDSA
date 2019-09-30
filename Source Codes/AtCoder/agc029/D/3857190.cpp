#include <set>
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200000 + 5;
int n, m, k;
vector<int> col[N];

void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        col[y].push_back(x);
    }
    for (int i = 1; i <= m; i++) {
        sort(col[i].begin(), col[i].end());
    }

    int ans = n;
    int x = 1, y = 1;
    for (int i = 0; i < n; i++) {
        auto ptr = lower_bound(col[y].begin(), col[y].end(), x);
        if (ptr != col[y].end()) {
            ans = min(ans, *ptr - 1);
            if (*ptr == x + 1) {
                break;
            }
        }
        x++;
        if (y < m && !binary_search(col[y + 1].begin(), col[y + 1].end(), x)) {
            y++;
        }
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}