#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char x, y;
    scanf("%c %c", &x, &y);
    if (x < y)
    {
        printf("<\n");
    }
    else if (x > y)
    {
        printf(">\n");
    }
    else
    {
        printf("=\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c %c", &x, &y);
     ^