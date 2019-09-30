#include <stdio.h>

int main()
{
  long int sx,sy,tx,ty;
  scanf("%ld %ld %ld %ld", &sx, &sy, &tx, &ty);
  long int dx=tx-sx, dy=ty-sy;
  
  for(int i=0;i<dy; i++)
    putchar('U');
  for(int i=0;i<dx;i++)
    putchar('R');
    
  for(int i=dy;i>0;i--)
    putchar('D');
  for(int i=dx;i>0;i--)
    putchar('L');
  
  putchar('L');
  for(int i=0;i<dy+1; i++)
    putchar('U');
  for(int i=0;i<dx+1;i++)
    putchar('R');
  putchar('D');
  
  putchar('R');
  for(int i=dy;i>-1;i--)
    putchar('D');
  for(int i=dx;i>-1;i--)
    putchar('L');
    
  putchar('U');
  
   
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld %ld %ld %ld", &sx, &sy, &tx, &ty);
   ^