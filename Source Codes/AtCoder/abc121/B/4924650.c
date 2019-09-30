#include <stdio.h>

int main()
{
    int N, M, C;
    scanf("%d%d%d",&N,&M,&C);
    
    int A[N][M], B[M];
    
    int i,j;
    
    for (i=0;i<M;i++) {
        scanf("%d",&B[i]);
    }
    
    for (i=0;i<N;i++) {
        for (j=0;j<M;j++) {
            scanf("%d",&A[i][j]);
        }
    }
    
    int sum[N], count = 0;
    
    for (i=0;i<N;i++) {
        sum[i] = 0;
    }
    
    for (i=0;i<N;i++) {
        for (j=0;j<M;j++) {
            sum[i] = sum[i] + A[i][j]*B[j];
        }
        if (sum[i] + C > 0) sum[i] = 1;
        else sum[i] = 0;
    }
    
    for (i=0;i<N;i++) {
        count = count + sum[i];
    }
        
    printf("%d\n",count);
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&N,&M,&C);
     ^
./Main.c:13:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&B[i]);
         ^
./Main.c:18:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&A[i][j]);
             ^