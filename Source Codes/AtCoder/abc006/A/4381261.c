#include <stdio.h>
int main(void){
    // Your code here!
    int n;
    scanf("%d",&n);
    if(n%3==0)
        printf("YES");
    else
        printf("NO");
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^