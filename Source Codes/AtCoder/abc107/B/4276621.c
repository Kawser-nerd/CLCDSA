#include<stdio.h>
int main(void){
    int H, W;
    scanf("%d %d",&H, &W);
    char a[H][W];
    for(int i = 0; i < H; i++){
        scanf("%s",a[i]);
    }

    int white = 1;
    int check_h[H], check_w[W];
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(a[i][j] == '#') white = 0;
            else white = 1;
            if(white == 0) break;
        }
        if(white == 1)  check_h[i] = 1;
        else check_h[i] = 0;
        white = 1;
    }

    white = 1;
    for(int i = 0; i < W; i++){
        for(int j = 0; j < H; j++){
            if(a[j][i] == '#') white = 0;
            else white = 1;
            if(white == 0) break;
        }
        if(white == 1)  check_w[i] = 1;
        else check_w[i] = 0;
        white = 1;
    }

    for(int i = 0; i < H; i++){
        if(check_h[i] == 1) continue;
        for(int j = 0; j < W; j++){
            if(check_w[j] == 1) continue;
            else printf("%c",a[i][j]);
        }
        printf("\n");
    }

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&H, &W);
     ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",a[i]);
         ^