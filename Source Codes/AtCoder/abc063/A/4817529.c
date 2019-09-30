#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a, b;
    scanf("%d%d%d", &a, &b);
    if (a + b > 9)
    {
        printf("error\n");
    }
    else
    {
        printf("%d\n", a + b);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:11: warning: format ‘%d’ expects a matching ‘int *’ argument [-Wformat=]
     scanf("%d%d%d", &a, &b);
           ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d", &a, &b);
     ^