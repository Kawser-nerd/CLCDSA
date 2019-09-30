#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 200000

int main(void){
    short int *x = (short int*)malloc(sizeof(short int)*N);
    short int *y = (short int*)malloc(sizeof(short int)*N);
    int flag = 0;
    for(int i=0; i<=N; i++){
        x[i] = 0;
        y[i] = 0;
    }

    int n, m;
    scanf("%d %d", &n, &m);

    int tempx, tempy;
    for(int i=0;i<=m;i++){
        scanf("%d %d", &tempx, &tempy);
        if(tempx==1){
            x[tempy] = 1;
        }
        if(tempy==n){
            y[tempx] = 1;
        }
    }

    for(int i=0; i<=n;i++){
        if(x[i]==1){
            if(y[i]==1){
                flag = 1;
                break;
            }
        }
    }

    if(flag==1){
        printf("POSSIBLE");
    }else{
        printf("IMPOSSIBLE");
    }
} ./Main.c: In function ‘main’:
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &m);
     ^
./Main.c:21:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &tempx, &tempy);
         ^