#include<stdio.h>
#include<math.h>
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    a = abs(a);
    b = abs(b);
    if (a < b)
        printf("Ant\n");
    else if (a > b)
        printf("Bug\n");
    else
        printf("Draw\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:9: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
     a = abs(a);
         ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &a, &b);
     ^