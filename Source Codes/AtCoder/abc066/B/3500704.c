#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    char s[201];
    scanf("%s", s);
    int i, j, lens_ini = strlen(s), count;
    for (i=lens_ini - 1; i>=2; i--)
    {
        s[i] = '\0';
        if (strlen(s) % 2 == 0) {
            count = 0;
            for (j=0; j<=(strlen(s)/2)-1; j++)
            {
                if (s[j] == s[j + strlen(s)/2]) count ++;
            }
            if (count == strlen(s)/2) break;
        }
    }
    printf("%d\n", count*2);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^