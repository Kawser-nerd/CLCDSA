#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, q;
    scanf(" %d %d %d", &n, &m, &q);
    vector<vector<int>> freq(n, vector<int>(n, 0));
    int l, r;
    while (m-- > 0) {
        scanf(" %d %d", &l, &r);
        --l; --r;
        ++freq[l][r];
    }
    vector<vector<int>> ans(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        ans[i][i] = freq[i][i];
        for (int j = i + 1; j < n; ++j) {
            ans[i][j] = ans[i][j - 1] + freq[i][j];
        }
    }

    vector<vector<int>> ans2(n, vector<int>(n, 0));
    for (int j = 0; j < n; ++j) {
        ans2[j][j] = ans[j][j];
        for (int i = j - 1; i >= 0; --i) {
            ans2[i][j] = ans2[i + 1][j] + ans[i][j];
        }
    }

    while (q-- > 0) {
        scanf(" %d %d", &l, &r);
        --l; --r;
        printf("%d\n", ans2[l][r]);
    }

    return 0;
}