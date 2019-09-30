#include <stdio.h>
int main(void){
    // Your code here!
    char c;
    scanf("%c",&c);
    printf("%d\n",c-'A'+1);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c",&c);
     ^