#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

typedef long long ll;

ll f[150][150], tot1[150][150], tot2[150][150];

struct Tuple {
    ll t, v;
} lef[150], righ[150];

int main() {
    freopen("D:\\C-large.in", "r", stdin);
    freopen("D:\\C-large.out", "w", stdout);
    int k, TotalCase, yyProblem, inputN, inputM, c = 0, x, i, j;
    scanf("%d", &TotalCase);
    while (TotalCase--) {
        ll best = 0;
        memset(f, 0, sizeof (f));
        memset(tot1, 0, sizeof (tot1));
        memset(tot2, 0, sizeof (tot2));
        scanf("%d%d", &inputN, &inputM);
        for (i = 0; i < inputN; i++) {
            scanf("%lld%lld", &lef[i].v, &lef[i].t);
            tot1[lef[i].t][i + 1] = lef[i].v;
        }
        for (i = 0; i < inputN; i++)
            for (k = 0; k <= 100; k++)
                tot1[k][i + 1] += tot1[k][i];
        for (i = 0; i < inputM; i++) {
            scanf("%lld%lld", &righ[i].v, &righ[i].t);
            tot2[righ[i].t][i + 1] = righ[i].v;
        }
        for (i = 0; i < inputM; i++)
            for (k = 0; k <= 100; k++)
                tot2[k][i + 1] += tot2[k][i];

        for (i = 1; i <= inputN; i++)
            for (j = 1; j <= inputM; j++) {
                if (lef[i - 1].t != righ[j - 1].t) {
                    f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                } else {
                    for (x = 0; x < i; x++)
                        for (yyProblem = 0; yyProblem < j; yyProblem++)
                            f[i][j] = max(f[i][j], f[x][yyProblem] + min(tot1[lef[i - 1].t][i] - tot1[lef[i - 1].t][x], tot2[righ[j - 1].t][j] - tot2[righ[j - 1].t][yyProblem]));
                }
            }
        for (i = 0; i <= inputN; i++)
            for (j = 0; j <= inputM; j++)
                best = max(best, f[i][j]);
        printf("Case #%d: %lld\n", ++c, best);
    }
    return 0;
}
