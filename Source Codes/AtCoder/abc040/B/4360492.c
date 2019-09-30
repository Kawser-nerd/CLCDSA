#include<stdio.h>
#include<math.h>

int main(void)
{
  int h, w, n, n2;
  int a, c, b=100000;
  scanf("%d", &n);
  n2 = (int)sqrt(n);
  for(h=1;h<=n2;h++)
      {
        w = n / h;
        a = n - w * h;                      //a??????
        if(h == 0)
          c = 0;
        else if(h < w)
          c = w - h;
        else
          c = h - w;
        a = a + c;

        if((b > a) && (a >= 0))
          b = a;
      }

    printf("%d\n", b);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^