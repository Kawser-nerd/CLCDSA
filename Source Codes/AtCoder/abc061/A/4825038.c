#include<stdio.h>
 
int main()
{
  int i, a, b, c;
  int d[3];
  scanf("%d %d %d", &a, &b, &c);
  d[0] = a, d[1] = b, d[2] = c;
  for(i = 0; i < 3; i++)
  {
    if(d[i] < -100 || d[i] > 100)
    {
      printf("wrong input\n");
      return 0;
    }
  }
  if(a <= c && b >= c)
    printf("Yes\n");
  else
    printf("No\n");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &a, &b, &c);
   ^