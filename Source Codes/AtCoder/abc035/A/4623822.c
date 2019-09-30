#include <stdio.h>
int main(void){
    // Your code here!
    int a,b;
    scanf("%d%d",&a,&b);
    if(a/4==b/3) printf("4:3\n");
    else printf("16:9\n");
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^