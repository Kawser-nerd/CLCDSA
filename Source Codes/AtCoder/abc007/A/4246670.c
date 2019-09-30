#include <stdio.h>

int main(int argc, char* argv[])
{
    int n = 0;
    scanf("%d", &n);

    printf("%d\n", (n-1));

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^