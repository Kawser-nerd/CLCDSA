#include <set>
#include <map>
#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 11;

bool mark[1 << MAXN][MAXN];
int v[MAXN][2];

int main() {
    int re, n;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d", &n);
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < 2; ++j) {
                scanf("%d", &v[i][j]);
                --v[i][j];
            }
        }
        fill(mark[0], mark[1 << n], false);

        int m = 0, s = 0, d = 0;
        while (!mark[m][s] && s != n - 1) {
            int t = v[s][(m & (1 << s)) == 0 ? 0 : 1];
            mark[m][s] = true;
            m ^= 1 << s;
            s = t;
            ++d;
        }

        printf("Case #%d: ", ri);
        if (s != n - 1) {
            puts("Infinity");
        } else {
            printf("%d\n", d);
        }
    }

    return 0;
}


