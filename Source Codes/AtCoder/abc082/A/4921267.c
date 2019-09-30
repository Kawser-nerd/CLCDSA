#include<stdio.h>
int main()
{
    int  a, b, x, z;
    float p;
    scanf("%d %d", &a, &b);
     z = (a + b) %2;
    if(z==0){
      x=(a+b)/2;
     printf("%d\n", x);
     }
    else
    {
     p = 1+a+b;
     x = p/2;
     printf("%d\n", x);
    }
     return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &a, &b);
     ^