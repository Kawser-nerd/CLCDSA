#include <stdio.h>

int main(void){
    char s[6];
    int a,b,c;
    scanf("%s%d",s,&a);
    b=(a-1)/5;
    c=(a-1)%5;
    printf("%c%c\n",s[b],s[c]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%d",s,&a);
     ^