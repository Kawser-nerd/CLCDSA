#include <algorithm>
#include <complex>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

using std::string;
using std::to_string;
using std::vector;
using std::set;
using std::queue;
using std::stack;
using std::priority_queue;

using std::min;
using std::max;
using std::sort;
using std::abs;

using std::pair;

typedef long long int ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;

int popcnt(int s) { return __builtin_popcount(s); }

bool valid(int s, int p) {
    if (p % 5 != 0 && p % 5 != 4) {
        bool l = (s & (1 << (p - 1))) != 0;
        bool r = (s & (1 << (p + 1))) != 0;
        if (l ^ r) {
            return false;
        }
    }

    if (p / 5 != 0 && p / 5 != 4) {
        bool u = (s & (1 << (p - 5))) != 0;
        bool d = (s & (1 << (p + 5))) != 0;
        if (u ^ d) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<vector<int>> a(5, vector<int>(5));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }

    vector<int> pos(25, -1);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (a[i][j] >= 0) {
                pos[a[i][j]] = 5 * i + j;
            }
        }
    }

    vector<int> dp(1 << 25);
    dp[0] = 1;

    for (int s = 1; s < (1 << 25); s++) {
        const int n = popcnt(s) - 1;
        if (pos[n] == -1) {
            int ans = 0;
            for (int p = 0; p < 25; p++) {
                if (!(s & (1 << p))) {
                    continue;
                }
                if (valid(s - (1 << p), p)) {
                    ans = (ans + dp[s - (1 << p)]) % MOD;
                }
            }
            dp[s] = ans;
        } else {
            int p = pos[n];
            if ((s & (1 << p)) && valid(s - (1 << p), p)) {
                dp[s] = dp[s - (1 << p)];
            }
        }
    }

    cout << dp[(1 << 25) - 1] << endl;

    return 0;
}