#include <stdio.h>

int main(int argc, char* argv[])
{
    int s = 0;
    int t = 0;
    scanf("%d %d", &s, &t);

    int num = 0;
    num = t - (s - 1);
    printf("%d\n", num);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &s, &t);
     ^