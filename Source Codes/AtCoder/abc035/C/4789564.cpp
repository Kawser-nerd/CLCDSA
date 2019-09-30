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
#include <set>
#include <stack>
#include <string>
#include <vector>

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
#define int long long
using ll = long long;
using namespace std;
const int INF = 1LL << 50;
using P       = pair<int, int>;

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

struct Setup {
    Setup() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} SETUP;

signed main() {
    int n, q;
    cin >> n >> q;
    vector<int> acc(n + 1, 0);
    rep(i, 0, q) {
        int l, r;
        cin >> l >> r;
        l--;
        acc[l]++, acc[r]--;
    }

    rep(i, 0, n) {
        acc[i + 1] += acc[i];
    }
    string ans;
    rep(i, 0, n) {
        // ????????? -> ?????????
        if (acc[i] % 2 == 0) {
            ans += '0';
        } else {
            ans += '1';
        }
    }
    cout << ans << endl;
}