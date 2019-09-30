#include <stdio.h>
int main(void){
    // Your code here!
    int a,b;
    scanf("%d%d",&a,&b);
    if(a>b)
        printf("Worse\n");
    else
        printf("Better\n");
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^