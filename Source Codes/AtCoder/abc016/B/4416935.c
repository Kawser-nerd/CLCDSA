#include <stdio.h>
int main(void){
    // Your code here!
    int a,b,n;
    scanf("%d%d%d",&a,&b,&n);
    if(a+b==n && a-b==n)
        printf("?\n");
    else if(a+b==n)
        printf("+\n");
    else if(a-b==n)
        printf("-\n");
    else
        printf("!\n");
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&n);
     ^