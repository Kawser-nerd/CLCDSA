#include <stdio.h>

int main(void)
{
    char s[12];
    int i;
    scanf ("%s", s);
    for (i = 0; s[i] != '\0'; i++)
    {
        if (i == 0 && s[i] >= 97 && s[i] <= 122) s[i] -= 32;
        if (i != 0 && s[i] >= 65 && s[i] <= 90) s[i] += 32;
    }
    printf ("%s", s);
    return (0);
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%s", s);
     ^