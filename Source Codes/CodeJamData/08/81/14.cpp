#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>

using namespace std;

typedef vector <int> vi;
typedef long long ll;
typedef double dbl;
typedef pair <int, int> pii;
typedef vector <string> vs;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forit(i, a) for (__typeof((a).begin() i = (a).begin(); i != (a).end(); i++)

#define m 9
#define eps 1e-9

dbl a[m][m], b[m], res[m], x[m][m], y[m][m];

int main()
{
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
  int nt;
  scanf("%d", &nt);
  forn (tn, nt)
  {
    printf("Case #%d: ", tn + 1);
    forn (i, 2)
      forn (j, 3)
        scanf("%lf%lf", &x[i][j], &y[i][j]);
    forn (i, 3)
    {
      a[i * 2 + 0][0] = x[0][i];
      a[i * 2 + 0][1] = y[0][i];
      a[i * 2 + 0][2] = 1.0;
      a[i * 2 + 0][3] = 0.0;
      a[i * 2 + 0][4] = 0.0;
      a[i * 2 + 0][5] = 0.0;
      b[i * 2 + 0] = x[1][i];
      a[i * 2 + 1][3] = x[0][i];
      a[i * 2 + 1][4] = y[0][i];
      a[i * 2 + 1][5] = 1.0;
      a[i * 2 + 1][0] = 0.0;
      a[i * 2 + 1][1] = 0.0;
      a[i * 2 + 1][2] = 0.0;
      b[i * 2 + 1] = y[1][i];
    }
    forn (i, 6)
    {
      int q = -1;
      for (int j = i; j < 6; j++)
        if (q == -1 || fabs(a[j][i]) > fabs(a[q][i]))
          q = j;
      if (q == -1 || fabs(a[q][i]) < eps)
        fprintf(stderr, "Botva!!!\n");
      swap(b[q], b[i]);
      forn (j, 6)
        swap(a[q][j], a[i][j]);
      for (int j = i + 1; j < 6; j++)
      {
        double c = a[j][i] / a[i][i];
        b[j] -= c * b[i];
        forn (k, 6)
          a[j][k] -= c * a[i][k];
      }
    }
    for (int i = 5; i >= 0; i--)
    {
      res[i] = b[i];
      for (int j = i + 1; j < 6; j++)
        res[i] -= res[j] * a[i][j];
      res[i] /= a[i][i];
    }
    dbl aa = res[0], bb = res[1], cc = res[2], dd = res[3], ee = res[4], ff = res[5];
    if (fabs((aa - 1) * (ee - 1) - bb * dd) < eps)
      printf("No Solution");
    else
    {
      dbl xx = ((-cc) * (ee - 1) - bb * (-ff)) / ((aa - 1) * (ee - 1) - bb * dd);
      dbl yy = ((aa - 1) * (-ff) - (-cc) * dd) / ((aa - 1) * (ee - 1) - bb * dd);
      printf("%.9lf %.9lf", xx, yy);
    }
    puts("");
  }
  return 0;
}

