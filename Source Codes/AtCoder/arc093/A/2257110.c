#include <stdio.h>

int absyai(int a,int b){return a>b?a-b:b-a;}

int main(void){
    int N;
    scanf("%d",&N);
    int A[N+2];
    for(int i=0;i<N;i++)scanf("%d",&A[i+1]);
    A[0]=0;
    A[N+1]=0;
    int karians=0;
    for(int i=1;i<=N+1;i++)karians+=absyai(A[i],A[i-1]);
    for(int i=1;i<=N;i++){
        printf("%d\n",karians-absyai(A[i],A[i-1])-absyai(A[i+1],A[i])+absyai(A[i+1],A[i-1]));
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:9:25: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(int i=0;i<N;i++)scanf("%d",&A[i+1]);
                         ^