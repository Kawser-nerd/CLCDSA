#include <stdio.h>

struct vertex {
  long long x;
  long long y;
};

int tcing(struct vertex a, struct vertex b, struct vertex c)
{
  long long xc;
  long long yc;
  xc = a.x + b.x + c.x;
  yc = a.y + b.y + c.y;
  return (((xc % 3) == 0) && ((yc % 3) == 0));
}

int main(int argc, char *argv[])
{
  int cases, i;
  scanf("%d\n", &cases);
  for (i = 1; i <= cases; i++) {
    int sol = 0;
    long long X, Y;
    long long n, A, B, C, D, x0, y0, M;
    int z;
    struct vertex vertice[100001];
    scanf("%lld %lld %lld %lld %lld %lld %lld %lld\n", &n, &A, &B, &C, &D, &x0, &y0, &M);
    X = x0;
    Y = y0;
    vertice[0].x = X;
    vertice[0].y = Y;
    for (z=1; z <= n-1; z++)
    {
      X = (A * X + B) % M;
      Y = (C * Y + D) % M;
      vertice[z].x = X;
      vertice[z].y = Y;
    }
    int a, b, c;
    for (a = 0; a < n - 2; a++)
    {
      for (b = a + 1; b < n - 1; b++)
      {
	for (c = b + 1; c < n; c++)
	{
	  if (tcing(vertice[a], vertice[b], vertice[c])) sol++;
	}
      }
    }
    printf("Case #%d: %d\n", i, sol);
  }
  return 0;
}

