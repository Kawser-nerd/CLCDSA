#include <stdio.h>
int main(void){
    // Your code here!
    int a;
    scanf("%d",&a);
    if(a==1)
        printf("ABC\n");
    else
        printf("chokudai\n");
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^