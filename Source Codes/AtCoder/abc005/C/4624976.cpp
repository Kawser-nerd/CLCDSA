#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

// #define INF 1000000000
#define MOD 1000000007
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
using P       = pair<int, int>;
const int INF = 1LL << 50;

struct Setup {
    Setup() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} SETUP;

template <class T>
bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    } else {
        return false;
    }
}

template <class T>
bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    } else {
        return false;
    }
}

signed main() {
    int t, n;
    cin >> t >> n;
    vector<int> as(n);
    rep(i, n) {
        cin >> as[i];
    }
    int m;
    cin >> m;
    vector<int> bs(m);
    rep(i, m) {
        cin >> bs[i];
    }

    int ai = 0, bi = 0;
    for (; bi < m; ai++, bi++) {
        if (ai >= n) goto NO;
        while (!(as[ai] <= bs[bi] && as[ai] + t >= bs[bi])) {
            ai++;
            if (ai >= n) goto NO;
        }
    }
    puts("yes");
    return 0;

NO:
    puts("no");
    return 0;

}