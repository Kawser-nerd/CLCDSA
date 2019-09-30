#include <stdio.h>
int main(void){
    char n[3];
    scanf("%s",n);
    if(n[0]==n[2]) printf("Yes");
    else printf("No");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",n);
     ^