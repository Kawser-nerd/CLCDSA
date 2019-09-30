#include <stdio.h>

int main(){

    int N, M, C;
    int i,j;
    int A[20][20], B[20];
    int sum, count=0;
    scanf("%d%d%d",&N,&M,&C);


    for(i=0;i<M;++i){
        scanf("%d",&B[i]);
    }
    for(i=0;i<N;++i){
        for(j=0;j<M;++j){
            scanf("%d",&A[i][j]);
        }
    }


    for(i=0;i<N;++i){

        sum=0;

        for(j=0;j<M;++j){
            sum += (A[i][j] * B[j]);
        }

        if(sum + C > 0){count++;}
    }

    printf("%d\n",count);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&N,&M,&C);
     ^
./Main.c:13:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&B[i]);
         ^
./Main.c:17:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&A[i][j]);
             ^