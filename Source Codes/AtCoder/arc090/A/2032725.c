#include <stdio.h>
int main(void){
    int i, j, max, sum, N, A[2][100] = {{0}};
    scanf("%d", &N);
    for(i=0;i<N;i++)scanf("%d", &(A[0][i]));
    for(i=0;i<N;i++)scanf("%d", &(A[1][i]));
    max = 0;
    for(i=0;i<N;i++){
        sum = 0;
        for(j=0;j<N;j++){
            if(j<=i)sum+=A[0][j];
            if(i<=j)sum+=A[1][j];
        }
        if(sum > max)max = sum;
    }
    printf("%d\n", max);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:5:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(i=0;i<N;i++)scanf("%d", &(A[0][i]));
                     ^
./Main.c:6:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(i=0;i<N;i++)scanf("%d", &(A[1][i]));
                     ^