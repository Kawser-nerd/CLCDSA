#include <stdio.h>
int main(void){
    char a[2],b[2];
    scanf("%s%s",a,b);
    printf("%s\n",a[0]=='H'?(b[0]=='H'?"H":"D"):(b[0]=='H'?"D":"H"));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%s",a,b);
     ^