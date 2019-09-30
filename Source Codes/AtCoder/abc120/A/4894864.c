#include<stdio.h>

int main(void)
{
  int a, b, c, d, x;

     scanf("%d%d%d", &a, &b, &c);

     x = b / a;

        if(x <= c)
          printf("%d\n", x);

        else
          printf("%d\n", c);


return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:6: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
      scanf("%d%d%d", &a, &b, &c);
      ^