#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int testCount, test;
int n, m;
vector<PII> a, b;
char f[100][100], f1[100][100], f2[100][100], res[100][100];
bool r[100], c[100];
map<PII, PII> ma;
set<int> d1, d2;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &testCount);
    for (test = 1; test <= testCount; ++test) {
        printf("Case #%d: ", test);

        cin >> n >> m;
        a.clear();
        b.clear();
        forn(i, n) forn(j, n) {
            f[i][j] = '.';
            f1[i][j] = '.';
            f2[i][j] = '.';
        }
        memset(r, 0, sizeof r);
        memset(c, 0, sizeof c);
        d1.clear();
        d2.clear();
        forn(i, m) {
            char cc;
            int x, y;
            scanf(" %c%d%d", &cc, &x, &y);
            --x, --y;
            if (cc == 'x' || cc == 'o') {
                a.pb(mp(x, y));
                r[x] = true;
                c[y] = true;
                f1[x][y] = 'x';
            }
            if (cc == '+' || cc == 'o') {
                b.pb(mp(x, y));
                f2[x][y] = '+';
                d1.insert(x + y);
                d2.insert(x - y);
            }
            f[x][y] = cc;
        }
        int rind = 0, cind = 0;
        while (true) {
            while (rind < n && r[rind]) ++rind;
            while (cind < n && c[cind]) ++cind;
            if (rind >= n || cind >= n) {
                break;
            }
            r[rind] = true;
            c[cind] = true;
            f1[rind][cind] = 'x';
        }
        ma.clear();
        forn(i, n) forn(j, n) {
            ma[mp(i + j, i - j)] = mp(i, j);
        }
        for (int i = 0, j = (n - 1) * 2; i <= j; ++i, --j) {
            forn(z, 2) {
                int ind = (z ? i : j);
                if (d1.count(ind)) {
                    continue;
                }
                for (int k = -n; k <= n; ++k) {
                    if (!d2.count(k) && ma.count(mp(ind, k))) {
                        d1.insert(ind);
                        d2.insert(k);
                        PII pos = ma[mp(ind, k)];
                        f2[pos.first][pos.second] = '+';
                        break;
                    }
                }
            }
        }

        int score = 0;
        int changed = 0;
        forn(i, n) forn(j, n) {
            if (f1[i][j] == '.') {
                res[i][j] = f2[i][j];
            } else if (f2[i][j] == '.') {
                res[i][j] = f1[i][j];
            } else {
                res[i][j] = 'o';
            }
            if (res[i][j] == 'o') {
                score += 2;
            } else if (res[i][j] != '.') {
                score += 1;
            }
            if (res[i][j] != f[i][j]) {
                ++changed;
            }
        }
        printf("%d %d\n", score, changed);
        forn(i, n) forn(j, n) {
            if (res[i][j] != f[i][j]) {
                printf("%c %d %d\n", res[i][j], i + 1, j + 1);
            }
        }
//        forn(i, n) {
//            forn(j, n) cerr << f[i][j];
//            cerr << endl;
//        }
//        cerr << endl;
//        forn(i, n) {
//            forn(j, n) cerr << res[i][j];
//            cerr << endl;
//        }

        cerr << "Done #" << test << endl;
    }
    return 0;
}
