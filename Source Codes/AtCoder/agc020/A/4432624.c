#include<stdio.h>
#include<math.h>
int main()
{
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    if (abs(a - b) % 2 == 0)
        printf("Alice\n");
    else
        printf("Borys\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:9: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
     if (abs(a - b) % 2 == 0)
         ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d", &n, &a, &b);
     ^