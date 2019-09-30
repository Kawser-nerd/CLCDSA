#include <stdio.h>
#include <string.h>

char res[50][50];
int r,c,m,tt;
int possible;

void printResult()
{
  printf("Case #%d:\n", tt);
  if (possible)
  {
    for (int i = 0; i < r; ++i)
    {
      printf("%.*s\n", c, res[i]);
    }
  }
  else
  {
    printf("Impossible\n");
  }
}

int main()
{
  int t;
  scanf("%d", &t);
  for (tt = 1; tt <= t; ++tt)
  {
    memset(res, '*', sizeof(res));
    possible = 1;
    scanf("%d %d %d", &r, &c, &m);
    int n = r*c - m;
    if (r == 1 || c == 1)
    {
      for (int i = 0; i < n; ++i) res[i/c][i%c] = '.';
      res[0][0] = 'c';
      printResult();
      continue;
    }
    if (n == 1)
    {
      res[0][0] = 'c';
      printResult();
      continue;
    }
    if (n == 2)
    {
      possible = (r*c == 2); 
      for (int i = 0; i < n; ++i) res[i/c][i%c] = '.';
      res[0][0] = 'c';
      printResult();
      continue;
    }
    if (r == 2)
    {
      possible = (n % 2 == 0);
      memset(res[0], '.', n/2);
      memset(res[1], '.', n/2);
      res[0][0] = 'c';
      printResult();
      continue;
    }
    if (c == 2)
    {
      possible = (n % 2 == 0);
      for (int i = 0; i < n/2; ++i) memset(res[i], '.', 2);
      res[0][0] = 'c';
      printResult();
      continue;
    }
    if (n >= 2*c && n != 7)
    {
      int rest = n % c;
      int fullrows = n / c;
      for (int i = 0; i < fullrows; ++i) memset(res[i], '.', c);
      memset(res[fullrows], '.', rest);
      if (rest == 1)
      {
        res[fullrows-1][c-1] = '*';
        res[fullrows][1] = '.';
        if (fullrows == 2)
        {
          res[fullrows-2][c-1] = '*';
          res[fullrows][2] = '.';
        }
      }
      res[0][0] = 'c';
      printResult();
      continue;
    }
    if (n % 2 == 0)
    {
      memset(res[0], '.', n/2);
      memset(res[1], '.', n/2);
      res[0][0] = 'c';
      printResult();
      continue;
    }
    else
    {
      if (n < 9)
      {
        possible = 0;
      }
      else
      {
        memset(res[0], '.', (n-3)/2);
        memset(res[1], '.', (n-3)/2);
        memset(res[2], '.', 3);
        res[0][0] = 'c';
      }
      printResult();
    }
  }
  return 0;
}
