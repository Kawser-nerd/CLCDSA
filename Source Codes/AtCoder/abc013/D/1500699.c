#include <stdio.h>


int main(void){
    int N,M,D;
    scanf("%d %d %d",&N,&M,&D);
    int A[N];
    int Ans[N];
    int po[N];
    int TrueAns[N];
    for(int i=0;i<N;i++){A[i]=i+1;Ans[i]=i+1;}
    for(int i=0;i<M;i++){
        int kari;
        scanf("%d",&kari);
        int tmp=A[kari-1];
        A[kari-1]=A[kari];
        A[kari]=tmp;
    }
    while(D!=0){
        if(D%2==1){
            for(int i=0;i<N;i++)po[i]=Ans[i];
            D-=1;
            for(int i=0;i<N;i++)Ans[i]=po[A[i]-1];
        }
        for(int i=0;i<N;i++)po[i]=A[i];
        for(int i=0;i<N;i++)A[i]=po[po[i]-1];
        D/=2;
    }
    for(int i=0;i<N;i++)TrueAns[Ans[i]-1]=i+1;
    for(int i=0;i<N;i++)printf("%d\n",TrueAns[i]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&N,&M,&D);
     ^
./Main.c:14:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&kari);
         ^