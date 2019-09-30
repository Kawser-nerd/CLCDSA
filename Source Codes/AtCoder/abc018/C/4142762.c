#include <stdbool.h>
#include <stdio.h>

static bool map[500][500];
static char buf[502];

int main() {
    int r, c, k;
    scanf("%d%d%d", &r, &c, &k);
    for (int y = 0; y < r; y++) {
        scanf("%s", buf);
        for (int x = 0; x < c; x++) {
            if (buf[x] == 'x') {
                for (int dy = -k + 1; dy < k; dy++) {
                    int mdx = k - (dy >= 0 ? dy : -dy);
                    for (int dx = -mdx + 1; dx < mdx; dx++) {
                        int x2 = x + dx;
                        int y2 = y + dy;
                        if (0 <= x2 && x2 < c && 0 <= y2 && y2 < r) {
                            map[y2][x2] = true;
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int y = k - 1; y < r - k + 1; y++) {
        for (int x = k - 1; x < c - k + 1; x++) {
            if (!map[y][x]) {
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d", &r, &c, &k);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s", buf);
         ^