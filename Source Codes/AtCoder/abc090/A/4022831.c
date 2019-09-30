#include <stdio.h>
int main(void){
    char a[3],b[3],c[3];
    scanf("%s%s%s",a,b,c);
    printf("%c%c%c",a[0],b[1],c[2]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%s%s",a,b,c);
     ^