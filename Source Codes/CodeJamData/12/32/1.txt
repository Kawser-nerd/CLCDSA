#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

const int MAXN = 2050;
const double eps = 1e-8;

double tablei[MAXN], zipi[MAXN], tempii;

int main() {
    int i, j, TotalCase, number, aaa, ccc = 0;
    double ddd,  v, best, tempt;
    //freopen("B.in", "r", stdin);
    //freopen("B.out", "w", stdout);
    scanf("%d", &TotalCase);
    while (TotalCase--) {
        scanf("%lf%d%d", &ddd, &number, &aaa);
        for (i = 0; i < number; i++)
            scanf("%lf%lf", &tablei[i], &zipi[i]);
        printf("Case #%d:\n", ++ccc);
        for (i = 0; i < aaa; i++) {
            scanf("%lf", &tempii);
            if (zipi[0] > ddd) {
                best = sqrt(2.0 * ddd / tempii);
                printf("%lf\n", best);
            } else {
                v = ((double) (zipi[1] - zipi[0]) / (tablei[1] - tablei[0]));
                tempt = (ddd - zipi[0]) / v;
                best = sqrt(2.0 * ddd / tempii);
                printf("%lf\n", max(best, tempt));
            }
        }
    }
    return 0;
}