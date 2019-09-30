#include <stdio.h>

int main(void){
    int N,M;
    scanf("%d %d",&N,&M);
    int ans=M*1900+(N-M)*100;
    ans<<=M;
    printf("%d",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&N,&M);
     ^