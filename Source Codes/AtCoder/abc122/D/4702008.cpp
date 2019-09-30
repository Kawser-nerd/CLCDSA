#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <numeric>

using namespace std;

using ll = long long;

ll mod = 1000000007;

int n;

map<pair<int, string>, ll> memo;

ll dfs(int i, string s) {
    if (i == n) {
        return 1;
    }

    auto cur = make_pair(i, s);

    if (memo.count(cur)) {
        return memo[cur];
    }

    ll ret = 0;

    string t = s.substr(1);
    ret = (ret + dfs(i + 1, t + 'A')) % mod;
    ret = (ret + dfs(i + 1, t + 'T')) % mod;

    if (t != "AC") {
        ret = (ret + dfs(i + 1, t + 'G')) % mod;
    }

    if (t != "AG" && t != "GA" && !(s[0] == 'A' && s[1] == 'G') && !(s[0] == 'A' && s[2] == 'G')) {
        ret = (ret + dfs(i + 1, t + 'C')) % mod;
    }

    return memo[cur] = ret;
}

int main() {
    cin >> n;

    cout << dfs(0, "TTT") << endl;
}