#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int descending_compare(const void *a, const void *b){
    return (int)(*(int*)b - *(int*)a);
}

int ascending_compare(const void *a, const void *b){
    return (int)*(int*)a - *(int*)b;
}

int c[10][10];
int a[200][200];

int main(void){
    int H, W;
    int i, j, k;
    int magicka = 0;
    scanf("%d %d", &H, &W);
    for (i = 0; i < 10; i++){
        for (j = 0; j < 10; j++){
            scanf("%d", &c[i][j]);
        }
    }

    for (i = 0; i < H; i++){
        for (j = 0; j < W; j++){
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < 10; i++){
        for (j = 0; j < 10; j++){
            for (k = 0; k < 10; k++){
                if (c[j][k] > c[j][i]+c[i][k]){
                    c[j][k] = c[j][i]+c[i][k];
                }
            }
        }    
    }

    for (i = 0; i < H; i++){
        for (j = 0; j < W; j++){
            if (a[i][j] > -1 && a[i][j] != 1){
                magicka += c[a[i][j]][1];
            }
        }
    }

    printf("%d\n", magicka);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &H, &W);
     ^
./Main.c:24:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d", &c[i][j]);
             ^
./Main.c:30:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d", &a[i][j]);
             ^