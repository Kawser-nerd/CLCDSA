#include <stdio.h>

int main()
{
    char a[8],s[101],c[8];
    scanf("%s %s %s",a,s,c);
    printf("A%cC",s[0]);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s %s %s",a,s,c);
     ^