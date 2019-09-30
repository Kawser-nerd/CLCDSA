#include <stdio.h>
static char s[100][101], white[100][101], black[100][101];
static int h, w;
void put(char dst[100][101], char c, int x, int y) {
    if (x < 0 || w <= x)
        return;
    if (y < 0 || h <= y)
        return;
    dst[y][x] = c;
}
void copy(char src[100][101], char dst[100][101], char small, char large) {
    int x, y;
    for (y = 0; y < h; ++y)
        for (x = 0; x < w; ++x)
            if (src[y][x] == small)
                dst[y][x] = small;
    for (y = 0; y < h; ++y)
        for (x = 0; x < w; ++x)
            if (src[y][x] == large) {
                put(dst, large, x - 1, y - 1);
                put(dst, large, x + 0, y - 1);
                put(dst, large, x + 1, y - 1);
                put(dst, large, x - 1, y);
                put(dst, large, x + 0, y);
                put(dst, large, x + 1, y);
                put(dst, large, x - 1, y + 1);
                put(dst, large, x + 0, y + 1);
                put(dst, large, x + 1, y + 1);
            }
}
int is_same(char src[100][101], char dst[100][101]) {
    int x, y;
    for (y = 0; y < h; ++y)
        for (x = 0; x < w; ++x)
            if (src[y][x] != dst[y][x])
                return 0;
    return 1;
}
void print(char css[100][101]) {
    int x, y;
    for (y = 0; y < h; ++y) {
        for (x = 0; x < w; ++x)
            printf("%c", css[y][x]);
        putchar('\n');
    }
}
int main(void) {
    int i;
    scanf("%d%d", &h, &w);
    for (i = 0; i < h; ++i)
        scanf("%s", s[i]);
//    puts("original:");
//    print(s);
    copy(s, white, '#', '.');
//    puts("white:");
//    print(white);
    copy(white, black, '.', '#');
//    puts("black:");
//    print(black);
    if (is_same(s, black)) {
        puts("possible");
        print(white);
    } else
        puts("impossible");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:49:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &h, &w);
     ^
./Main.c:51:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s", s[i]);
         ^