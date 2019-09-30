#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;

int sx, sy, x, y;

int main() {
    freopen("b1.out", "w", stdout);
    int t, ca = 0;
    scanf("%d", &t);
    while (t--) {
        printf("Case #%d: ", ++ca);
        scanf("%d%d", &sx, &sy);
        x = abs(sx);
        y = abs(sy);
        for (int i = 0; i < x; ++i) {
            if (sx < 0) printf("EW");
            else printf("WE");
        }
        for (int i = 0; i < y; ++i) {
            if (sy < 0) printf("NS");
            else printf("SN");
        }
        printf("\n");
    }
    return 0;
}

