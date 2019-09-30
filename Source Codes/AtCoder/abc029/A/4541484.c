#include <stdio.h>
int main(void){
    // Your code here!
    char s[11];
    scanf("%s",s);
    printf("%ss\n",s);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^