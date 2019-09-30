#include <stdio.h>
int main(void){
    char S[10] = {"0"};
    scanf("%s", S);
    S[3] = '8';
    printf("%s\n", S);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", S);
     ^