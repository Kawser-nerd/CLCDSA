#include<stdio.h>
#include<stdlib.h>

int compare_int(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}
int compare_int2(const void *a, const void *b){
    return *(int*)b - *(int*)a;
}


int main(void){
    int N,M;
    scanf("%d %d",&N,&M);
        int X[M];
        for(int i=0;i<M;i++){
            scanf("%d",&X[i]);
        }
    if(N<M){
        qsort(X,sizeof(X)/sizeof(int),sizeof(int),compare_int);
        int L[M-1];
        for(int i=0;i<M-1;i++){
            L[i] = X[i+1]-X[i];
        }
        qsort(L,sizeof(L)/sizeof(int),sizeof(int),compare_int2);
        int sum = 0;
        for(int i=0;i<N-1;i++){
            sum += L[i];
        }
        printf("%d",X[M-1]-X[0]-sum);
    }else{
        printf("0");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&N,&M);
     ^
./Main.c:17:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&X[i]);
             ^