#include <stdio.h>
#include<string.h>
int main(void){
    char C,c;
    scanf("%c %c",&C,&c);
    if(strcmp(&C,&c)==-32)printf("Yes\n");
    else printf("No\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c %c",&C,&c);
     ^