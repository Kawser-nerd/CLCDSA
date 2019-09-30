#include <stdio.h>
int main(void){
    // Your code here!
    int n,x;
    scanf("%d%d",&n,&x);
    if(n/2>=x)
        printf("%d\n",x-1);
    else
        printf("%d\n",n-x);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&x);
     ^