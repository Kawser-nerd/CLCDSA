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

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define MOD 1000000007
#define int long long
using ll = long long;
using namespace std;
const int INF = 1LL << 50;
using P       = pair<int, int>;

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

template <typename T>
T gcd(T a, T b) {
    return b ? gcd(b, a % b) : a;
}

template <typename T>
T lcm(T a, T b) {
    // return (a * b) / gcd(a, b);
    T g = gcd(a,b);
    return a / g * b;
}

signed main() {
    int n;
    cin >> n;
    int ans = 1;
    rep(i, 0, n) {
        int t;
        cin >> t;
        ans = lcm<int>(ans, t);
    }
    cout << ans << endl;
}