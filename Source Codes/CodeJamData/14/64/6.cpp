#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
#include <cmath>
#include <iostream>
#include <string>
#include <ctime>
#include <sstream>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

double curtime() {
    return double(clock()) / CLOCKS_PER_SEC;
}

int n, A;
char s[110][110];
int a[110];
bool u[110];
int uf[110], it;
int q[110], qb, qf;

bool can(int c, int put) {
    if (c == A) {
        forn(i, n) if (s[i][c] == 'Y' && !u[i]) return false;
        return true;
    }

    it++;
    qb = qf = 0;
    q[qf++] = A;
    uf[A] = it;

    while (qb < qf) {
        int x = q[qb++];
        if (x == put) continue;
        forn(j, n)
            if (s[x][j] == 'Y' && uf[j] != it && !u[j]) {
                q[qf++] = j;
                uf[j] = it;
            }
    }

    //printf("can %d:", c); forn(i, qf) printf(" %d", q[i]); printf("\n");

    forn(j, n)
        if (uf[j] != it && u[j] != true && s[c][j] != 'Y')
            return false;

    return true;
}

void solve() {
    scanf("%d %d", &n, &A);
    forn(i, n) scanf("%s", s[i]);

    forn(i, n) u[i] = false;

    int c = -1;
    forn(i, n) {
        if (can(i, i)) {
            c = i;
            break;
        }
    }

    if (c == -1) {
        printf("IMPOSSIBLE\n");
        return;
    }

    u[c] = true;
    a[0] = c;
    //printf("a[%d] = %d\n", 0, c);
    for (int i = 1; i < n; i++) {
        if (c == A) {
            forn(j, n)
                if (!u[j]) {
                    u[j] = true;
                    a[i] = j;
                    break;
                }
        } else {
            a[i] = -1;
            forn(j, n) {
                if (u[j]) continue;
                int cc = c;
                if (s[j][cc] == 'Y') cc = j;
                if (j == A && cc != j) continue;
                if (can(cc, j)) {
                    a[i] = j;
                    c = cc;
                    break;
                }
            }
            if (a[i] == -1) {
                printf("IMPOSSIBLE\n");
                return;
            }
            u[ a[i] ] = true;
        }
        //printf("a[%d] = %d\n", i, a[i]);
    }

    forn(i, n) printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        printf("Case #%d: ", t);
        solve();
        fprintf(stderr, "Test %d done, time: %.5f sec.\n", t, curtime());
    }
	return 0;
}
