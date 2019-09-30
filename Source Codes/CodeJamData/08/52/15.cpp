#include <cstdio>
#include <map>
#include <vector>

using namespace std;

typedef vector <int> vi;

#define pb push_back
#define mm 1000000
#define m 55
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

map <vector <int>, int> r;
vector <int> q[mm + mm];
int pi[m][m][4], pj[m][m][4], nt, h, w;
char a[m][m];
int fi, la;
int di[4] = {1, 0, -1, 0};
int dj[4] = {0, -1, 0, 1};

void addq( int ii, int jj, int bi, int bj, int yi, int yj, int di, int dd )
{
  vi st;
  st.pb(ii);
  st.pb(jj);
  st.pb(bi);
  st.pb(bj);
  st.pb(yi);
  st.pb(yj);
  if (!r.count(st) || r[st] > di)
  {
    if (dd == 0)
      q[--fi] = st;
    else
      q[la++] = st;
    r[st] = di;
  }
}

bool ok( int i, int j )
{
  return 0 <= i && i < h && 0 <= j && j < w;
}

int main()
{
  freopen("portal.in", "r", stdin);
  freopen("portal.out", "w", stdout);
  scanf("%d", &nt);
  forn (tt, nt)
  {
    printf("Case #%d: ", tt + 1);
    fprintf(stderr, "%d\n", tt);
    scanf("%d%d", &h, &w);
    forn (i, h)
      scanf("%s", a[i]);
    int si = -1, sj = -1, ei = -1, ej = -1;
    forn (i, h)
      forn (j, w)
        if (a[i][j] == 'O')
          si = i, sj = j, a[i][j] = '.';
        else if (a[i][j] == 'X')
          ei = i, ej = j, a[i][j] = '.';

//    printf("pre 1\n");

    forn (i, h)
      forn (j, w)
        if (a[i][j] == '.')
          forn (k, 4)
          {
            int ii = i, jj = j;
            while (ok(ii + di[k], jj + dj[k]) && a[ii + di[k]][jj + dj[k]] == '.')
              ii += di[k], jj += dj[k];
            pi[i][j][k] = ii;
            pj[i][j][k] = jj;
          }

//    printf("pre 2\n");

    r.clear();
    fi = la = m;
    addq(si, sj, -1, -1, -1, -1, 0, 0);
    int res = -1;
    while (fi < la)
    {

//      printf("bfs\n");

      vi st = q[fi++];
      int ii = st[0], jj = st[1], bi = st[2], bj = st[3],
        yi = st[4], yj = st[5], rr = r[st];
      if (rr > w * h)
        continue;

//      printf("ii=%d jj=%d bi=%d bj=%d yi=%d yj=%d rr=%d\n", ii, jj, bi, bj, yi, yj, rr);

      if (ii == ei && jj == ej)
      {
        res = rr;
        break;
      }
      forn (k, 4)
        addq(ii, jj, pi[ii][jj][k], pj[ii][jj][k], yi, yj, rr, 0);
      forn (k, 4)
        addq(ii, jj, bi, bj, pi[ii][jj][k], pj[ii][jj][k], rr, 0);
      forn (k, 4)
        if (ok(ii + di[k], jj + dj[k]) && a[ii + di[k]][jj + dj[k]] == '.')
          addq(ii + di[k], jj + dj[k], bi, bj, yi, yj, rr + 1, 1);
      if (ii == bi && jj == bj && yi != -1)
        addq(yi, yj, bi, bj, yi, yj, rr + 1, 1);
      if (ii == yi && jj == yj && bi != -1)
        addq(bi, bj, bi, bj, yi, yj, rr + 1, 1);
    }
    if (res == -1)
      printf("THE CAKE IS A LIE\n");
    else
      printf("%d\n", res);
  }
  return 0;
}
