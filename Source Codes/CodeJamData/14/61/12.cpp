#include <cstdio>
#include <queue>
#include <set>
#include <vector>
#include <cmath>
#include <iostream>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
string a[2048], b[2048];

void read() {
    cin >> n;
    n *= 2;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        a[i] = b[i];
    }
}

const int INF = (1 << 30) - 5;

int get(string s) {
    string anti = s;
    for (int i = 0; i < n; i++) {
        if (anti[i] == '0') anti[i] = '1';
        else anti[i] = '0';
    }
    vector<int> f[2];
    for (int i = 0; i < n; i++) {
        if (a[i] != s && a[i] != anti) return INF;
        if (a[i] == s) {
            if (!(i & 1)) f[0].push_back(i);
        }
        else {
            if (i & 1) f[1].push_back(i);
        }
    }
    if (f[0].size() != f[1].size()) return INF;

    int ans = 0;
    while ((int)f[0].size()) {
        swap(a[ f[0].back() ], a[ f[1].back() ]);
        f[0].pop_back();
        f[1].pop_back();
        ans ++;
    }

    string c1 = "", c2 = "";
    for (int j = 0; j < n; j++) {
        c1 += a[j][0];
        if (a[j][0] == '0') c2 += '1';
        else c2 += '0';
    }

    for (int j = 0; j < n; j++) {
        string cc;
        for (int i = 0; i < n; i++) {
            cc += a[i][j];
        }
        //cout << cc << endl;
        //printf ("%d %d\n", ans, ans);
        if (cc != c1 && cc != c2) {
            return INF;
        }
    }
    //printf (" -- %d\n", ans);

    int cur[2];
    cur[0] = cur[1] = 0;
    for (int j = 0; j < n; j++) {
        if ((a[0][0] != a[0][j]) ^ (j % 2 == 0)) {
            cur[j % 2] ++;
        }
    }
    if (cur[0] != cur[1]) return INF;
    ans += min(cur[0], (n - 2 * cur[0]) / 2);

    //printf ( " -- %d\n", ans);

    return ans;
}

void solve() {
    string fst = a[0];

    int ans = get(fst);
    for (int j = 0; j < n; j++) {
        a[j] = b[j];

        if (fst[j] == '0') fst[j] = '1';
        else fst[j] = '0';
    }
    ans = min(ans, get(fst));

    //printf ("%d\n", ans);

    if (ans >= INF)
        printf ("IMPOSSIBLE\n");
    else
        printf ("%d\n", ans);
}

int main() {
    int cases;

    cin >> cases;
    for (int i = 1; i <= cases; i++) {
        read();
        printf ("Case #%d: ", i);
        solve();
    }

    return 0;
}

