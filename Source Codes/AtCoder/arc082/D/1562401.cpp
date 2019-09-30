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

using i64 = long long;

i64 X, K;
i64 r[101010];
i64 Q;
i64 t[101010], a[101010];

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> X >> K;
    for (int j = 0; j < K; ++j) {
        cin >> r[j];
    }
    cin >> Q;
    for (int j = 0; j < Q; ++j) {
        cin >> t[j] >> a[j];
    }

    i64 sr[101010];
    sr[0] = 0;
    for (int j = 0; j < K; ++j) {
        i64 offset = (j == 0) ? r[0] : (r[j] - r[j-1]);
        i64 s = (j % 2 == 0) ? -1 : 1;
        sr[j+1] = sr[j] + s * offset;
    }

    i64 la = 0, ha = X, s = -1;

    i64 l[101010], h[101010];
    i64 ml[101010], mh[101010];
    l[0] = 0; h[0] = X;
    ml[0] = 0; mh[0] = X;

    for (int j = 0; j < K; ++j) {
        i64 offset = j == 0 ? r[0] : r[j] - r[j-1];
        la += s * offset;
        ha += s * offset;

        l[j+1] = max(0LL, min(X, l[j] + s * offset));
        h[j+1] = max(0LL, min(X, h[j] + s * offset));

        ml[j+1] = max(ml[j], -la);
        mh[j+1] = min(mh[j], X - (ha - X));

        s *= -1;
    }

    for (int j = K; j > 0; --j) r[j] = r[j-1];
    r[0] = 0;
    for (int j = 0; j < Q; ++j) {
        int idx = upper_bound(r, r+K+1, t[j]) - r - 1;
        i64 s = (idx % 2 == 0) ? -1 : 1;
        i64 offset = t[j] - r[idx];
        if (a[j] < ml[idx]) {
            cout << max(0LL, min(X, l[idx] + s * offset)) << endl;
        } else if (mh[idx] < a[j]) {
            cout << max(0LL, min(X, h[idx] + s * offset)) << endl;
        } else {
            cout << max(0LL, min(X, a[j] + sr[idx] + s * offset)) << endl;
        }
    }
    return 0;
}