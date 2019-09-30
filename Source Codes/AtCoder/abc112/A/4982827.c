#include <stdio.h>
#include <stdlib.h>
int fw(const void *a, const void *b)
{
    return *(long int *)a - *(long int *)b;
}
int bw(const void *a, const void *b)
{
    return *(long int *)b - *(long int *)a;
}
int main()
{
    int a, b, x;
    scanf("%d %d %d", &x, &a, &b);
    if (x == 1)
    {
        printf("Hello World");
    }
    if (x == 2)
    {
        printf("%d", a + b);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d", &x, &a, &b);
     ^