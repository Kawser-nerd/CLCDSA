#include <stdio.h>

int main(void){
    int H, W; 
    scanf("%d%d", &H, &W);
    int grid[H][W];
    char tmp[W];
    int black1[H];
    int black2[W];
    for(int i = 0; i < H; i++){
        black1[i] = 0;
        scanf("%s", tmp);
        for(int j = 0; j < W; j++){
            if(i == 0) black2[j] = 0;
            grid[i][j] = (tmp[j] == '#') ? 1 : 0;
            black1[i] += grid[i][j];
            black2[j] += grid[i][j];
        }
    }

    for(int i = 0; i < H; i++){
        if(black1[i] == 0) continue;
        for(int j = 0; j < W; j++){
            if(black2[j] == 0) continue;
            printf("%c", grid[i][j] ? '#' : '.');
        }
        printf("\n");
    }

    return 0; 
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &H, &W);
     ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s", tmp);
         ^