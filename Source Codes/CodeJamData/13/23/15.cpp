#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <memory.h>

using namespace std;

vector<string> v;

void prep() {
    FILE* f = fopen("dict.txt", "r");
    char s[100];
    while (fscanf(f, "%s", s) != EOF) {
        v.push_back(s);
        string d(s);
        for (int i = 0; i < d.length(); ++i) {
            d[i] = ' ';
            v.push_back(d);
            d[i] = s[i];
        }
        for (int i = 0; i < d.length(); ++i) for (int j = i + 5; j < d.length(); ++j) {
            d[i] = d[j] = ' ';
            v.push_back(d);
            d[i] = s[i]; d[j] = s[j];
        }
    }
    sort(v.begin(), v.end());
}

bool check(const string& s) {
    return binary_search(v.begin(), v.end(), s);
}

string s;
int memo[5000][20];

int F(int p, int prev) {
    if (p == s.length()) return 0;

    if (prev > 10) prev = 10;
    int& res = memo[p][prev];
    if (res >= 0) return res;

    res = 5000;

    for (int l = 1; l <= 10 && p + l <= s.length(); ++l) {
        string sub = s.substr(p, l);
        if (check(sub)) res = min(res, F(p + l, prev + l));
        for (int i = 0; i < l; ++i) {
            if (i + prev >= 5) {
                sub[i] = ' ';
                if (check(sub)) res = min(res, F(p + l, l - i) + 1);
                sub[i] = s[p + i];
            }
        }
        for (int i = 0; i < l; ++i) if (i + prev >= 5) for (int j = i + 5; j < l; ++j) {
            sub[i] = sub[j] = ' ';
            if (check(sub)) res = min(res, F(p + l, l - j) + 2);
            sub[i] = s[p + i];
            sub[j] = s[p + j];
        }
    }

    return res;
}

void solve() {
    int ans = 0;

    cin >> s;

    memset(memo, -1, sizeof memo);
    ans = F(0, 10);
/*
    for (int i = 0; i <= s.length(); ++i) {
        for (int p = 1; p <= 11; ++p)
            printf("%5d", memo[i][p]);
        puts("");
    }
*/
    static int testid;
    cout << "Case #" << ++testid << ": " << ans << endl;
}

int main() {
    prep();
    cerr << v.size() << endl;
    cerr << (double) clock() / CLOCKS_PER_SEC << endl;

    int tests;
    cin >> tests;
    while (tests --> 0)
        solve();

    cerr << (double) clock() / CLOCKS_PER_SEC << endl;
    return 0;
}
