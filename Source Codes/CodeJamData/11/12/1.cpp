#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 10005;

int t1, n, m, mh, mi, id[maxn], f[maxn][26], C;
string T, s[maxn];

bool cmplength(int a, int b)
{
    return s[a].size() < s[b].size();
}

bool cmpword(int a, int b)
{
    return f[a][C] < f[b][C];
}

void dfs(int l, int r, int p, int h)
{
    if (l == r) {
        if (h > mh || (h == mh && id[l] < mi)) {
            mh = h;
            mi = id[l];
        }
        return;
    }
    if (p == -1) {
        sort(id + l, id + r + 1, cmplength);
        for (int i = l, j = l; i <= r; ++i)
            if (i == r || s[id[i]].size() != s[id[i + 1]].size()) {
                dfs(j, i, 0, h);
                j = i + 1;
            }
    }else {
        C = T[p] - 'a';
        sort(id + l, id + r + 1, cmpword);
        int c = C;
        if (f[id[r]][c] == 0)
            dfs(l, r, p + 1, h);
        else
            for (int i = l, j = l; i <= r; ++i)
                if (i == r || f[id[i]][c] != f[id[i + 1]][c]) {
                    dfs(j, i, p + 1, h + (f[id[i]][c] == 0));
                    j = i + 1;
                }
    }
}

int main()
{
    freopen("b2.in", "r", stdin);
    freopen("b2.out", "w", stdout);
    
    cin >> t1;
    for (int t2 = 1; t2 <= t1; ++t2) {
        cin >> n >> m;
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; ++i) {
            cin >> s[i];
            id[i] = i;
            for (int j = 0; j < 26; ++j)
                for (int k = 0; k < s[i].size(); ++k) {
                    f[i][j] *= 2;
                    if (s[i][k] == 'a' + j) ++f[i][j];
                }
        }
        cout << "Case #" << t2 << ": ";
        for (int i = 1; i <= m; ++i) {
            cin >> T;
            mh = 0; mi = 1;
            dfs(1, n, -1, 0);
            cout << s[mi] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
