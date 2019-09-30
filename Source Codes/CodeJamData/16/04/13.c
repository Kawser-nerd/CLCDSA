#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void solve(int k, int c, int s)
{
    int r, i, j, ns;
    uint64_t p;

    for (r = 0; r < 2; r++) {
        ns = 0;
        for (i = 0; i < k; i++) {
            p = i;
            for (j = 1; j < c; j++) {
                p = (p * k) + (p % k);
                if (i + 1 < k) {
                    p++;
                    i++;
                }
            }
            if (r == 0) {
                ns++;
            } else {
                printf(" %llu", p + 1);
            }
        }
        if ((r == 0) && (s < ns)) {
            printf(" IMPOSSIBLE");
            break;
        }
    }
}

int main() {
    int t;
    int k, c, s;
    scanf("%d", &t);
    for (int i=0;i<t;i++) {
        scanf("%d %d %d", &k, &c, &s);
        printf("Case #%d:", i+1);
        solve(k, c, s);
        puts("");
    }
    return 0;
}
