#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int H, W, h, w;
    scanf("%d%d%d%d", &H, &W, &h, &w);
    if (H % h == 0 && W % w == 0){
        printf("No");
        return 0;
    }
    printf("Yes\n");
    int m[H][W];
    for (int i = 0; i < H; ++i){
        for (int j = 0; j < W; ++j){
            if ((i + 1) % h ==0 && (j + 1) % w == 0)
                m[i][j] = -1e9;
            else
                if (i % h == 0 && j % w == 0)
                    m[i][j] = 1e9 - 1;
                else
                    m[i][j] = 0;
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d", &H, &W, &h, &w);
     ^