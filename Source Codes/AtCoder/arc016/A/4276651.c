#include<stdio.h>
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    if (m == 1)
        printf("2\n");
    else
        printf("1\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &m);
     ^