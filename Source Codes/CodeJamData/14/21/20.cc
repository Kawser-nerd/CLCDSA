#include <bits/stdc++.h>
using namespace std;

char s[110];

struct B {
    int a[110], id[110];
    int sz;
};

B a[110];

void ck(char *s, B &ans) {
    int pos = 0, n = strlen(s);
    ans.sz = 0;
    while (pos < n) {
        ans.id[ans.sz] = s[pos] - 'a';
        char c = s[pos];
        int tot = 0;
        while (pos < n && s[pos] == c) {
            pos++;
            tot++;
        }
        ans.a[ans.sz] = tot;
        ans.sz++;
    }
}

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s", s);
            ck(s, a[i]);
        }
        int sz = 0;
        for (int i = 0; i < n; i++) {
            sz = max(sz, a[i].sz);
        }
        bool sol = true;
        for (int i = 0; i < n; i++) {
            if (a[i].sz != sz) sol = false;
        }
        int ans = 0;
        if (sol) {
            for (int i = 0; i < sz; i++) {
                vector<int> g;
                int id = a[0].id[i];
                for (int j = 0; j < n; j++) {
                    if (a[j].id[i] != id) sol = false;
                    else {
                        g.push_back(a[j].a[i]);
                    }
                }
                if (!sol) break;
                sort(g.begin(), g.end());
                for (int j = 0; j <= n - 1 - j; j++) {
                    ans += g[n - 1 - j] - g[j];
                }
            }
        }
        printf("Case #%d: ", cas);
        if (!sol) puts("Fegla Won");
        else printf("%d\n", ans);
    }
    return 0;
}
