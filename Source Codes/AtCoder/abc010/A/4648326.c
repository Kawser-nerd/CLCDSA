#include <stdio.h>
int main(void){
    char s[11];
    scanf("%s",s);
    printf("%spp\n",s);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^