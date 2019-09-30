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

bool check(string &s, string t, int si) {
    for (int ti = 0; ti < (int)t.size(); ti++, si++) {
        if (s[si] != '?' && s[si] != t[ti]) {
            return false;
        }
        if (s[si] == '?') {
            s[si] = t[ti];
        }
    }
    return true;
}

signed main() {
    string s, t;
    cin >> s >> t;
    const int s_len = (int)s.size();
    set<string> st;
    rep(i, 0, s_len) {
        if (s[i] == '?' || s[i] == t[0]) {
            string ss = s;
            if (check(ss, t, i)) {
                rep(j, 0, s_len) {
                    if (ss[j] == '?') ss[j] = 'a';
                }
                st.insert(ss);
            }
        }
    }

    if (st.empty()) {
        puts("UNRESTORABLE");
    } else {
        cout << *st.begin() << endl;
    }
}