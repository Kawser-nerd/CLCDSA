#include <stdio.h>
#include <string.h>
int main(void)
{
    char a[10],s[105],c[10];
    scanf("%s%s%s", a,s,c);
    printf("A%cC",s[0]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%s%s", a,s,c);
     ^