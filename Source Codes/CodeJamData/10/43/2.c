#include<stdio.h>
#include<string.h>

int main(void)
{
  int ca = 1, c, r, x1, y1, x2, y2, i, j, q, f, k;
  int m[128][128];
  
  scanf("%d", &c);
  
  while(ca <= c)
  {
    q = 0;
       
    scanf("%d", &r);
  
    memset(m, 0, sizeof(m));
    
    for(k = 0; k < r; k++)
    {
      scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
      for(i = x1; i <= x2; i++)
      {
	for(j = y1; j <= y2; j++)
	{
	  m[i][j] = 1;
	}
      }
    }
    
    while(1)
    {
      f = 0;
      
      for(i = 100; i >= 1; i--)
      {
	for(j = 100; j >= 1; j--)
	{
	  if(m[i][j] == 0)
	  {
	    if(i > 1 && m[i-1][j] == 1 && j > 1 && m[i][j-1] == 1) {m[i][j] = 1; f = 1;}
	  }
	  else
	  {
	    if((i > 1 && m[i-1][j] == 1) || (j > 1 && m[i][j-1] == 1)) f = 1;
	    else m[i][j] = 0;
	  }
	}
      }
      
      q++;
      if(f == 0) break;
    }
    
    printf("Case #%d: %d\n", ca, q);
    ca++;
  }
  
  return 0;
}