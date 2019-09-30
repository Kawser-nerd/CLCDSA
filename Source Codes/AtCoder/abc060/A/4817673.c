#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[10] = {0}, b[10] = {0}, c[10] = {0};
    scanf("%s%s%s", a, b, c);
    int lena = strlen(a), lenb = strlen(b);
    if (a[lena - 1] == b[0] && b[lenb - 1] == c[0])
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%s%s", a, b, c);
     ^