#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);
  
  int a[1000];
  for (int t=1; t<=T; t++)
  {
    int N;
    scanf("%d", &N);
    for (int i=0; i<N; i++)
      scanf("%d", &a[i]);
      
    int m1 = 0;
    for (int i=1; i<N; i++)
      if (a[i-1] > a[i])
        m1 += a[i-1] - a[i];

    int m2 = -1;
    for (int f = 0; f <= 10000; f++)
    {
      int eat = 0;
      for (int i=1; i<N; i++)
        if (a[i-1] - f > a[i])
          goto fail;
        else
          eat += a[i-1] >= f ? f : a[i-1];
      if (eat < m2 || m2 == -1)
        m2 = eat;
fail:;
    }
    
    printf("Case #%d: %d %d\n", t, m1, m2);
  }
  return 0;
}
