#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

using namespace std;
using ull = unsigned long long;
using P = pair<int, int>;

static constexpr ull MOD = 1000000007;
static constexpr double pi = 3.14159265359;

int main() {
    int V[3];
    cin >> V[0] >> V[1] >> V[2];

    int ans = -1;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j) continue;
            for (int k = 0; k < 3; ++k) {
                if (i == k || j == k) continue;
                ans = max(ans, 10 * V[i] + V[j] + V[k]);
                ans = max(ans, V[i] + 10 * V[j] + V[k]);
            }
        }
    }
    cout << ans << endl;
}