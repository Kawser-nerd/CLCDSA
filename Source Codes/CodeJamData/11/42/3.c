#include <stdio.h>

char a[500][501];

unsigned long w[501][501];
unsigned long ww[501][501];
unsigned long wr[501][501];
unsigned long wc[501][501];

int min(int a, int b) { return a<b?a:b; }

int main()
{
  int T;
  scanf("%d ", &T);
  for (int t=1; t<=T; t++)
  {
    int r, c, d;
    scanf("%d %d %d ", &r, &c, &d);
    for (int i=0; i<r; i++)
      scanf("%s ", a[i]);
    for (int rr = 0; rr < r; rr++)
      for (int cc = 0; cc < c; cc++)
      {
        w[rr+1][cc+1] = a[rr][cc]-'0';
        ww[rr+1][cc+1] = w[rr+1][cc+1] + ww[rr][cc+1] + ww[rr+1][cc] - ww[rr][cc];
        wr[rr+1][cc+1] = w[rr+1][cc+1]*(rr+1) + wr[rr][cc+1] + wr[rr+1][cc] - wr[rr][cc];
        wc[rr+1][cc+1] = w[rr+1][cc+1]*(cc+1) + wc[rr][cc+1] + wc[rr+1][cc] - wc[rr][cc];
      }

    int k;
    for (k = min(r,c); k >= 3; k--)
      for (int rs = 0; rs + k <= r; rs++)
        for (int cs = 0; cs + k <= c; cs++)
        {
          int tr = wr[rs + k][cs + k] - wr[rs][cs+k] - wr[rs+k][cs] + wr[rs][cs];
          int tc = wc[rs + k][cs + k] - wc[rs][cs+k] - wc[rs+k][cs] + wc[rs][cs];
          int tw = ww[rs + k][cs + k] - ww[rs][cs+k] - ww[rs+k][cs] + ww[rs][cs];
          tr -= w[rs+k][cs+k]*(rs+k);
          tr -= w[rs+k][cs+1]*(rs+k);
          tr -= w[rs+1][cs+k]*(rs+1);
          tr -= w[rs+1][cs+1]*(rs+1);
          tc -= w[rs+k][cs+k]*(cs+k);
          tc -= w[rs+k][cs+1]*(cs+1);
          tc -= w[rs+1][cs+k]*(cs+k);
          tc -= w[rs+1][cs+1]*(cs+1);
          tw -= w[rs+k][cs+k];
          tw -= w[rs+k][cs+1];
          tw -= w[rs+1][cs+k];
          tw -= w[rs+1][cs+1];

          tr = 2*tr - (2*rs+k+1)*tw;
          tc = 2*tc - (2*cs+k+1)*tw;
          if (tr == 0 && tc == 0)
            goto FOUND;
        }
FOUND:
    if (k < 3)
      printf("Case #%d: IMPOSSIBLE\n", t);
    else
      printf("Case #%d: %d\n", t, k);
  }
  return 0;
}
