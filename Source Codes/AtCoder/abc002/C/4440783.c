#include<stdio.h>
#include<math.h>

int main()
{
    int x[6];
    int i = 0;
    for(; i < 6; i++)
        scanf("%d", x + i);
    
    int a = x[2] - x[0];
    int b = x[3] - x[1];
    int c = x[4] - x[0];
    int d = x[5] - x[1];

    double ans = (double)abs(a * d - b * c) / 2;

    printf("%lf\n", ans);
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:26: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
     double ans = (double)abs(a * d - b * c) / 2;
                          ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", x + i);
         ^