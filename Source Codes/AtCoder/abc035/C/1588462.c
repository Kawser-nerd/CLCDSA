#include <stdio.h>
int main(void){
    int N,Q;
    scanf("%d %d",&N,&Q);
    int po[N+1];
    for(int i=0;i<N+1;i++)po[i]=0;
    int nari,buri;
    for(int i=0;i<Q;i++){
        scanf("%d %d",&nari,&buri);
        po[nari-1]++;
        po[buri]--;
    }
    printf("%d",po[0]%2);
    for(int i=1;i<N;i++){
        po[i]+=po[i-1];
        printf("%d",po[i]%2);
    }
    printf("\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&N,&Q);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d",&nari,&buri);
         ^