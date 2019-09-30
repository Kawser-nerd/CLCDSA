#include <stdio.h>
int main(void){
    char s[3][101];
    scanf("%s%s%s",s[0],s[1],s[2]);
    printf("%c%c%c\n",s[0][0],s[1][0],s[2][0]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%s%s",s[0],s[1],s[2]);
     ^