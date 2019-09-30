#include <stdio.h>
int main(void){
    // Your code here!
    int N,i;
    scanf("%d %d",&N,&i);
    printf("%d",N+1-i);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&N,&i);
     ^