#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    char s[201];
    scanf("%s", s);
    int lens = strlen(s), i;
    for (i=lens - 2; i>=2; i-=2)
    {
        if (strncmp(s, s+i/2, i/2) == 0) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^