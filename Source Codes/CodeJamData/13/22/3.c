#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  int numcases, casecount;
  scanf("%d", &numcases);
  for(casecount = 1; casecount <= numcases; casecount++)
    {
      int numdiam, x, y;
      scanf("%d", &numdiam);
      scanf("%d", &x);
      scanf("%d", &y);
      if(numdiam < 1)
	{
	  printf("Case #%d: 0.0\n", casecount);
	  continue;
	}
      if(x < 0) x = -x;
 
      int n = 1;
      while(((n*n) + n) <= 2*numdiam)
	n+=2;
      n-=2;
      if(n-1 >= y + x)
	{
	  printf("Case #%d: 1.0\n", casecount);
	  continue;
	}
      if(y + x >= n + 3)
	{
	  printf("Case #%d: 0.0\n", casecount);
	  continue;
	}
      int d = numdiam - ((n*n) +n)/2;
      if((d - n - 2) >= y)
	{
	  printf("Case #%d: 1.0\n", casecount);
	  continue;
	}
      if((d - 1) < y || y >= n + 1)
	{
	  printf("Case #%d: 0.0\n", casecount);
	  continue;
	}
      double* pgaus = (double*)malloc(sizeof(double)*(y+2));
      double* pgaustwo = (double*)malloc(sizeof(double)*(y+2));
      int i, j;
      for(i=0; i<y+2; i++)
	{
	  pgaus[i] = 0.0;
	  pgaustwo[j] =  0.0;
	}
      pgaus[0] = 1.0;
      for(i = 0; i< d; i++)
	{
	  for(j = 0; j< y+2; j++)
	    {
	      pgaustwo[j] += 0.5*pgaus[j];
	      if(j + 1 < y+2)
		pgaustwo[j+1] +=0.5*pgaus[j];
	      else
		pgaustwo[j] += 0.5*pgaus[j];
	    }
	  for(j=0; j<y+2; j++)
	    {
	      pgaus[j] = pgaustwo[j];
	      pgaustwo[j] = 0.0;
	    }
	}
      printf("Case #%d: %f\n", casecount, pgaus[y+1]);
      /* free(pgaus);
	 free(pgaustwo); */
    }
  return 0;
}
      
