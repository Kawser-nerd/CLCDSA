#include <stdio.h>
#include <stdlib.h>
int K,M;
unsigned A[1000];
unsigned B[1000];
unsigned tmp1[1000][1000];
unsigned tmp2[1000][1000];
unsigned (*t1)[1000],(*t2)[1000],(*tmp)[1000];

unsigned *sol2(){
    int i,j,k;
    for(i=0;i<K;i++){
        for(j=0;j<K;j++){
            for(k=0;k<K;k++){
                if(k==0){
                    t2[i][j]=t1[i][k]&t1[k][j];
                }else{
                    t2[i][j]^=t1[i][k]&t1[k][j];
                }
            }
        }
    }
    tmp=t1;
    t1=t2;
    t2=tmp;
}

int main(){
    scanf("%d %d",&K,&M);
    int i,j,k,l;
    for(i=0;i<K;i++){
        scanf("%u",&A[K-i-1]);
    }
    for(i=0;i<K;i++){
        scanf("%u",&tmp1[0][i]);
    }
    if(K>=M){
        printf("%u\n",A[K-M]);
        return 0;
    }
    for(i=1;i<K;i++){
        for(j=0;j<K;j++){
            if(i==j+1){
                tmp1[i][j]=~0;
            }else{
                tmp1[i][j]=0;
            }
        }
    }
    t1=tmp1;
    t2=tmp2;("\n");
    for(i=1;i<=M-K;i*=2){
        if((M-K)&i){
            for(j=0;j<K;j++){
                B[j]=0;
                for(k=0;k<K;k++){
                    B[j]^=t1[j][k]&A[k];
                }
            }
            for(j=0;j<K;j++){
                A[j]=B[j];
            }
        }
        sol2();
    }
    printf("%u\n",A[0]);
} ./Main.c: In function ‘main’:
./Main.c:29:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&K,&M);
     ^
./Main.c:32:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%u",&A[K-i-1]);
         ^
./Main.c:35:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%u",&tmp1[0][i]);
         ^