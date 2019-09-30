#include <stdio.h>
int main(void){
    // Your code here!
    int t;
    scanf("%d",&t);
    printf("%02d:%02d:%02d\n",t/3600,t%3600/60,t%3600%60);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&t);
     ^