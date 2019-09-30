#include <stdio.h>
int main(void){
    char s[20];
    
    scanf("%s",s);
    s[3] = '8';
    
    printf("%s",s);

} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^