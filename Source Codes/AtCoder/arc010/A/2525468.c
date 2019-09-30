#include <stdio.h>
 
 
 
int main(void){
    int N,M,A,B;
    scanf("%d %d %d %d",&N,&M,&A,&B);
    
    for(int i=0;i<M;i++){
        if(N<=A)N+=B;
        int c;
        scanf("%d",&c);
        N-=c;
        if(N<0){printf("%d\n",i+1);return 0;}
    }
    printf("complete\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d %d",&N,&M,&A,&B);
     ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&c);
         ^