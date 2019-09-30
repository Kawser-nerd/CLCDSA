#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ull = unsigned long long;

int main() {
    int N, K;
    cin >> N >> K;

    stack<pair<int, int>> dfs;
    dfs.push({1, 0});
    int ans = 999999999;
    while (!dfs.empty()) {
        auto n = dfs.top();
        dfs.pop();
        if (n.second < N) {
            dfs.push({2 * n.first, n.second + 1});
            dfs.push({n.first + K, n.second + 1});
        } else {
            ans = min(ans, n.first);
        }
    }
    cout << ans << endl;
}