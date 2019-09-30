#include <algorithm>
#include <cctype>
#include <complex>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::to_string;
using std::vector;
using std::set;
using std::queue;
using std::priority_queue;

using std::min;
using std::max;
using std::sort;
using std::abs;

class Item {
   public:
    int a;
    int b;
    int c;
    Item() {}
    Item(int a, int b, int c) : a(a), b(b), c(c) {}
};

const int INF = 1e9;

int main(void) {
    int n, ma, mb;
    cin >> n >> ma >> mb;

    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        items[i] = Item(a, b, c);
    }

    vector<vector<vector<int>>> dp(
        401, vector<vector<int>>(401, vector<int>(n + 1, INF)));

    fill(dp[0][0].begin(), dp[0][0].end(), 0);

    for (int i = 1; i <= 400; i++) {
        for (int j = 1; j <= 400; j++) {
            for (int k = 1; k <= n; k++) {
                dp[i][j][k] = dp[i][j][k - 1];
                int rest_a = i - items[k - 1].a;
                int rest_b = j - items[k - 1].b;
                if (rest_a >= 0 && rest_b >= 0) {
                    dp[i][j][k] =
                        min(dp[i][j][k],
                            items[k - 1].c + dp[rest_a][rest_b][k - 1]);
                }
            }
        }
    }

    int ans = INF;
    for (int i = 1; i * ma <= 400 && i * mb <= 400; i++) {
        ans = min(ans, dp[i * ma][i * mb][n]);
    }
    cout << (ans == INF ? -1 : ans) << endl;

    return 0;
}