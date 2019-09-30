#include <cstdio>
#include <string>

using namespace std;

const int mv = 2030;
const int mw = 25;
const int mq = mw * mw * mv;

int fi, la;
int w, n, qi[mq], qj[mq], qv[mq];
int d[mw][mw][mv];
string be[mw][mw][mv];
char s[mw][mw];
int di[] = {1, 0, -1, 0};
int dj[] = {0, -1, 0, 1};
string res[mq];

void addq( int i, int j, int v, int di, string t )
{
  if (d[i][j][v] != -1 && d[i][j][v] < di)
    return;
  if (d[i][j][v] == di && t >= be[i][j][v])
    return;
  d[i][j][v] = di, be[i][j][v] = t;
  qi[la] = i, qj[la] = j, qv[la] = v;
  la++;
//  if (v > mv / 2)
//    fprintf(stderr, "i=%d j=%d v=%d di=%d\n", i, j, v - mv / 2, di);
  if (res[v] == "" || res[v].length() > t.length() || res[v].length() == t.length() && res[v] > t)
  {
//    if (v > mv / 2)
//      fprintf(stderr, "addq: %d %d %d %d %s\n", i, j, v - mv / 2, di, "");
    res[v] = t;
  }
}

int C;

int main()
{
  int nt;
  scanf("%d", &nt);
  for (int tt = 1; tt <= nt; tt++)
  {
    printf("Case #%d:\n", tt);
    fprintf(stderr, "Case #%d:\n", tt);
    scanf("%d%d", &w, &n);
    for (int i = 0; i < w; i++)
      scanf("%s", s[i]);
    for (int i = 0; i < w; i++)
      for (int j = 0; j < w; j++)
        for (int k = 0; k < mv; k++)
          d[i][j][k] = -1;
    if (s[0][0] == '-' || s[0][0] == '+')
      C = 0;
    else
      C = 1;
    for (int i = 0; i < mv; i++)
      res[i] = "";
    fi = la = 0;
    for (int i = 0; i < w; i++)
      for (int j = 0; j < w; j++)
        if ((i + j + C) & 1)
        {
          string t = "";
          t += s[i][j];
          addq(i, j, s[i][j] - '0' + mv / 2, 1, t);
//          fprintf(stderr, "i=%d j=%d %c\n", i, j, s[i][j]);
        }
    while (fi < la)
    {
      int i = qi[fi], j = qj[fi], v = qv[fi];
      fi++;
      for (int k = 0; k < 4; k++)
      {
        int ii = i + di[k], jj = j + dj[k];
        if (ii < 0 || ii >= w || jj < 0 || jj >= w)
          continue;
        int vv = v;
        string tt = be[i][j][v];
        if ((ii + jj + C) & 1)
        {
          vv += ((s[i][j] == '-') ? -1 : 1) * (s[ii][jj] - '0');
          tt = tt + s[i][j] + s[ii][jj];
        }
        if (vv < 0 || vv >= mv)
          continue;
        addq(ii, jj, vv, d[i][j][v] + 1, tt);
      }
    }
    while (n--)
    {
      int x;
      scanf("%d", &x);
      x += mv / 2;
      printf("%s\n", res[x].c_str());
    }
  }
  return 0;
}
