#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

using ll = long long;

int N, Z, W, a[2020];

int dp1[2020], dp2[2020];

int main() {
    cin >> N >> Z >> W;
    for (int j = 0; j < N; ++j) cin >> a[j];

    for (int j = N-2; j >= 0; --j) {
        int s1 = abs(a[j] - a[N-1]), s2 = abs(a[j] - a[N-1]);
        for (int k = j+1; k < N-1; ++k) {
            if (s1 < dp1[k]) {
                s1 = dp1[k];
            }
            if (s2 > dp2[k]) {
                s2 = dp2[k];
            }
        }
        dp1[j] = s2;
        dp2[j] = s1;
    }

    int ans = abs(a[N-1] - W);
    for (int j = 0; j < N-1; ++j) {
        ans = max(ans, dp1[j]);
    }
    cout << ans << endl;
    return 0;
}