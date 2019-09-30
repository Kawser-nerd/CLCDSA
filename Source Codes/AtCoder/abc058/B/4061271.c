#include <stdio.h>

int main(void)
{
    char o[55], e[55];
    int i;
    scanf ("%s %s", o, e);
    for (i = 0; o[i] != '\0'; i++)
    {
        if (o[i] == '\0' && e[i] == '\0') break;
        else if (e[i] == '\0') printf ("%c", o[i]);
        else printf ("%c%c", o[i], e[i]);
    }
    return (0);
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%s %s", o, e);
     ^