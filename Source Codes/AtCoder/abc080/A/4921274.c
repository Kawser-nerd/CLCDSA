#include<stdio.h>
int main(){
    int N,A,B,D;
    scanf("%d %d %d",&N,&A,&B);
    D=N*A;
    if(D<=B) printf("%d\n",D);
    else printf("%d\n",B);


    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&N,&A,&B);
     ^