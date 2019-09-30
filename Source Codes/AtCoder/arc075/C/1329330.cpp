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

using int64 = int64_t;

constexpr int64 MOD = 1000000007;

template<int64 N>
struct BIT {
    int64 arr[N+1];

    BIT(int sz) {
        fill(arr, arr+N+1, 0);
    }

    void add(int x, int64 v) {
        for (int i = x; i <= N; i += i & -i) {
            arr[i] += v;
        }
    }

    int64 sum(int x) {
        int64 ans = 0;
        for (int i = x; i > 0; i -= i & -i) {
            ans += arr[i];
        }
        return ans;
    }
};

int N, K;
int64 a[200001];

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> K;
    for (int j = 1; j <= N; ++j) {
        cin >> a[j];
        a[j] -= K;
    }

    vector<int64> rv;

    a[0] = 0;
    for (int j = 1; j <= N; ++j) {
        a[j] += a[j-1];
        rv.push_back(a[j]);
    }
    sort(begin(rv), end(rv));

    int64 ans = 0;
    BIT<200000> bit(N);
    for (int j = N; j >= 1; --j) {
        if (a[j] >= 0) ++ans;
        int idx = lower_bound(begin(rv), end(rv), a[j]) - begin(rv) + 1;
        ans += bit.sum(N) - bit.sum(idx-1);
        bit.add(idx, 1);
    }
    cout << ans << endl;
    return 0;
}