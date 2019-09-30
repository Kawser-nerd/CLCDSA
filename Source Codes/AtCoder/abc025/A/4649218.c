#include <stdio.h>
int main(void){
    char s[6];
    int n;
    scanf("%s%d",s,&n);
    printf("%c%c\n",s[(n-1)/5],s[(n-1)%5]);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%d",s,&n);
     ^