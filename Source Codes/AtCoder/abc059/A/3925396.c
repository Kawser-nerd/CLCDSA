#include <stdio.h>
int main()
{   char a[11],b[11],c[11];
    scanf("%s%s%s",a,b,c);
    printf("%c%c%c",'A'+(a[0]-'a'),'A'+(b[0]-'a'),'A'+(c[0]-'a'));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%s%s",a,b,c);
     ^