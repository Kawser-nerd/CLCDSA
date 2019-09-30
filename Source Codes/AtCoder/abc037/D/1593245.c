#include <stdio.h>
#define M 1000000007
static int h, w, a[1000][1000], b[1000][1000];
int is_available(int x1, int y1, int x2, int y2) {
    if (x2 < 0 || w - 1 < x2)
        return 0;
    if (y2 < 0 || h - 1 < y2)
        return 0;
    if (a[y2][x2] <= a[y1][x1])
        return 0;
    return 1;
}
int f(int x, int y) {
    int sum = 1;
    if (b[y][x])
        return b[y][x];
    if (is_available(x, y, x - 1, y)) {
        sum += f(x - 1, y);
        sum %= M;
    }
    if (is_available(x, y, x + 1, y)) {
        sum += f(x + 1, y);
        sum %= M;
    }
    if (is_available(x, y, x, y - 1)) {
        sum += f(x, y - 1);
        sum %= M;
    }
    if (is_available(x, y, x, y + 1)) {
        sum += f(x, y + 1);
        sum %= M;
    }
    b[y][x] = sum;
    return sum;
}
int main(void) {
    int x, y, sum = 0;
    scanf("%d%d", &h, &w);
    for (y = 0; y < h; ++y)
        for (x = 0; x < w; ++x)
            scanf("%d", &a[y][x]);
    for (y = 0; y < h; ++y)
        for (x = 0; x < w; ++x)
            f(x, y);
    for (y = 0; y < h; ++y)
        for (x = 0; x < w; ++x) {
            sum += b[y][x];
            sum %= M;
        }
    printf("%d\n", sum);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:38:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &h, &w);
     ^
./Main.c:41:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d", &a[y][x]);
             ^