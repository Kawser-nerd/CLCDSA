#include <stdio.h>

int main(void) 
{
    int H, W, i, j;
    scanf("%d %d", &H, &W);
    char a[H+3][W+3];
    int h[H+1], w[W+1];
    for(i = 0; i < H; ++i) { h[i] = 1; }
    for(i = 0; i < W; ++i) { w[i] = 1; }
    for(i = 0; i < H; ++i) {
        scanf("%s", a[i]);
    }

    int flag = 0;
    for(i = 0; i < H; ++i) {
        for(j = 0; j < W; ++j) {
            if(a[i][j] == '#') { flag = 1; break; }
        }
        if(!flag) { h[i] = 0; }
        flag = 0;
    }

    flag = 0;
    for(i = 0; i < W; ++i) {
        for(j = 0; j < H; ++j) {
            if(a[j][i] == '#') { flag = 1; break; }
        }
        if(!flag) { w[i] = 0; }
        flag = 0;
    }

    //printf("\n");
    //printf("h: ");
    //for(i = 0; i < H; ++i) { printf(" %d", h[i]); } printf("\n");
    //printf("w: ");
    //for(i = 0; i < W; ++i) { printf(" %d", w[i]); } printf("\n");
    for(i = 0; i < H; ++i) {
        for(j = 0; j < W; ++j) {
            if((h[i] == 1) && (w[j] == 1)) { printf("%c", a[i][j]); }
        }
        if(h[i] == 1) { printf("\n"); }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &H, &W);
     ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s", a[i]);
         ^