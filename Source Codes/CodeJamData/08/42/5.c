#include <stdio.h>

int x0 = 0, y0, x1, y1 = 0, x2, y2;

int calc(int n, int m, int a)
{
     int s;
     for (x0 = 0; x0 <= n; x0++)
	  for (y1 = 0; y1 <= m; y1++) {
	       for (x2 = 0; x2 <= n; x2++)
		    for (y2 = 0; y2 <= m; y2++) {
			 s = abs((x1-x0)*(y2-y0)-(x2-x0)*(y1-y0));
			 if (s == a)
			      return 1;
		    }
	  }
     return 0;
}

int main()
{
     int c, i;
     scanf("%d", &c);
     for (i = 1; i <= c; i++) {
	  int n, m, a;
	  scanf("%d %d %d", &n, &m, &a);
	  int f = calc(n, m, a);
	  if (f)
	       printf("Case #%d: %d %d %d %d %d %d\n", i, x0, y0, x1, y1, x2, y2);
	  else
	       printf("Case #%d: IMPOSSIBLE\n", i);
     }
     
     return 0;
}
