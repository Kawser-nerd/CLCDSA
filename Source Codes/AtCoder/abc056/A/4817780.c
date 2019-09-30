#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a, b;
    scanf("%c %c", &a, &b);
    if (a == 'H')
    {
        printf("%c\n", b);
    }
    else
    {
        if (b == 'H')
        {
            printf("D\n");
        }
        else
        {
            printf("H\n");
        }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c %c", &a, &b);
     ^