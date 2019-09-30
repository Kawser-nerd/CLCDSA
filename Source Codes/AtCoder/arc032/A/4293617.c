#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    if (n == 2)
        printf("WANWAN\n");
    else
        printf("BOWWOW\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^