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
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)

#define pb push_back
#define mp make_pair
#define se second
#define fi first

int main()
{
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
  int nt;
  scanf("%d", &nt);
  forn (tn, nt)
  {
    printf("Case #%d: ", tn + 1);
    fprintf(stderr, "tn=%d\n", tn);
    int n;
    scanf("%d", &n);
    int ans = n + 1;
    map <string, vector <pii> > ma;
    forn (i, n)
    {
      int a, b;
      char tt[99];
      scanf("%s%d%d", tt, &a, &b);
//      fprintf(stderr, "!\n");
      ma[tt].pb(mp(a, b));
    }
    ma["dummy1"] = vector <pii> (0);
    ma["dummy2"] = vector <pii> (0);
    forit (p1, ma)
      sort(p1->second.begin(), p1->second.end());
    forit (p1, ma) forit (p2, ma) forit (p3, ma)
      if (p1->first < p2->first && p2->first < p3->first)
      {
//        fprintf(stderr, "%s %s %s\n", p1->first.c_str(), p2->first.c_str(), p3->first.c_str());
        vector <pii> &v1 = p1->second;
        vector <pii> &v2 = p2->second;
        vector <pii> &v3 = p3->second;
        vector <pii> wt, w;
        int i = 0, j = 0;
        while (i < (int)v1.size() || j < (int)v2.size())
          if (i == (int)v1.size() || (j < (int)v2.size() && v1[i] > v2[j]))
            wt.pb(v2[j++]);
          else
            wt.pb(v1[i++]);
        i = 0, j = 0;
        while (i < (int)wt.size() || j < (int)v3.size())
          if (i == (int)wt.size() || (j < (int)v3.size() && wt[i] > v3[j]))
            w.pb(v3[j++]);
          else
            w.pb(wt[i++]);
        int la = 0, su = 0;
        i = 0;
        while (la < 10000 && i < (int)w.size())
        {
          int nla = 0;
          while (i < (int)w.size() && w[i].fi <= la + 1)
            nla = max(nla, w[i].se), i++;
          su++;
          la = nla;
          if (la <= 0)
            break;
        }
        if (la >= 10000)
        {
//          fprintf(stderr, "su=%d\n", su);
          ans = min(ans, su);
        }
      }
    if (ans > n)
      printf("IMPOSSIBLE");
    else
      printf("%d", ans);
    puts("");
  }
  return 0;
}

