#include <stdio.h>
int main(){
char s[15];
    scanf("%s",s);
    s[3]='8';
    printf("%s",s);
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^