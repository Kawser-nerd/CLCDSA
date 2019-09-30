/*
  Number Game
  Author: Piotr Różański
  Compiler: GCC
*/

#include <stdio.h>

int main(void)
{
  unsigned test, testy;
  scanf("%u",&testy);
  for (test=1; test<=testy; ++test)
  {
    int a1,a2,b1,b2;
    scanf("%d %d %d %d",&a1,&a2,&b1,&b2);

    int A,B;
    long wygr = 0;
    for (A=a1; A<=a2; ++A) for (B=b1; B<=b2; ++B)
    {
      int a=A, b=B, r, t;
      if (a<b) t=a, a=b, b=t;
      int i=0;
      
      while (b)
      {
        t = a / b;
        r = a % b;
        if (t > 1)
        {
          if ((i&1)==0) ++wygr;
          break;
        }
        ++i;
        a = b;
        b = r;
      }
      if (b==0 && (i&1)==0) ++wygr;
    }
    printf("Case #%u: %ld\n",test,wygr);
  }
  return 0;
}
