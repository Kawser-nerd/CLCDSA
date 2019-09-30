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

void solve(string s) {
    for (auto &c : s) {
        if (c == '?') c = 'a';
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
    exit(0);
}

signed main() {
    string s, t;
    cin >> s >> t;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    const int s_len = (int)s.size();
    const int t_len = (int)t.size();
    rep(i, 0, s_len) {
        if (s[i] == t[0] || s[i] == '?') {
            string sa = s.substr(i, t_len);
            if ((int)sa.size() < t_len) continue;

            bool ok = true;
            rep(j, 0, t_len) {
                if (sa[j] != t[j] && sa[j] != '?') {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                rep(j, 0, t_len) {
                    s[i++] = t[j];
                }
                solve(s);
            }
        }
    }
    puts("UNRESTORABLE");
}