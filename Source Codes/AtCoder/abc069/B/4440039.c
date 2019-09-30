#include <stdio.h>
#include <string.h>

int main(void){
    char s[101];
    
    scanf("%s",s);
    printf("%c%lu%c", s[0], strlen(s)-2, s[strlen(s)-1]);
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^