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

signed main() {
    int n;
    cin >> n;
    set<int> st;
    rep(i, 0, n) {
        int a;
        cin >> a;
        while (a % 2 == 0) {
            a /= 2;
        }
        st.insert(a);
    }
    cout << st.size() << endl;
}