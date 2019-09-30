#include <stdio.h>
int main ()
{
    int a, b, x;
    scanf ("%d %d %d", &x, &a, &b);
    if ((x>=1) && (x<=1000) && (a>=1) && (x<=1000) && (b>=1) && (x<=1000)){

    a = abs (a-x);
    b = abs (b-x);
    if (a>b)
    {
        printf("B\n");
    }
    else printf ("A\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:9: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
     a = abs (a-x);
         ^
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%d %d %d", &x, &a, &b);
     ^