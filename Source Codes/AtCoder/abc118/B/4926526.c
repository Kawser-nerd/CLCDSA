#include<stdio.h>

int main(void){
    int N, M;
    int Human[30] = {0};
    int Food[30][30] = {0};
    int i, j, k, l, p;
    int minN = 31;
    int minIdx;
    int right = 0;
    int answer = 0;

    scanf("%d %d", &N, &M);
    for(i = 0; i < N; i++){
        scanf("%d", &Human[i]);
        for(j = 0; j < Human[i]; j++){
            scanf("%d", &Food[i][j]);
        }
        if(minN > Human[i]){
            minN = Human[i];
            minIdx = i;
        }
    }

    for(k = 0; k < minN; k++){
        for(l = 0; l < N; l++){
            for(p = 0; p < Human[l]; p++){
                if(Food[minIdx][k] == Food[l][p]){right++;}
            }
        }
        if(right == N){answer++;}
        right = 0;
    }
    
    printf("%d\n", answer);
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &N, &M);
     ^
./Main.c:15:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &Human[i]);
         ^
./Main.c:17:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d", &Food[i][j]);
             ^