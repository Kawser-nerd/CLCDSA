#include <stdio.h>
#include <stdlib.h>

int do_it(int line[], int from, int to)
{
  int i, ret = 0;
  for(i=from;i<=to;i++)
  {
    if(line[i])
    {
      int x = do_it(line, from, i-1) + do_it(line, i+1, to) + (to - from);
      if(!ret || x<ret)
      {
        ret = x;
      }
    }
  }
  return ret;
}

int main()
{
  int N,i;
  scanf("%d", &N);
  for(i=0;i<N;i++)
  {
    int line[10000] = {0};
    int P,Q,j;
    scanf("%d %d", &P, &Q);
    for(j=0;j<Q;j++)
    {
      int x;
      scanf("%d", &x);
      line[x-1] = 1;
    }
    printf("Case #%d: %d\n", i+1, do_it(line, 0, P-1));
  }
  return 0;
}
