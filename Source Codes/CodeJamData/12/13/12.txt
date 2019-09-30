#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

typedef long double cfloat;

const cfloat eps = 1e-8;

#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define REP(i,n) FOR(i,0,n)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define INF 1000000000
#define X first
#define Y second
#define pb push_back


int r[64];
int u[64];

cfloat pp[64];

cfloat solve(cfloat p1, cfloat s1, cfloat p2, cfloat s2) {
  return (p2-p1) / (s1-s2);
}

int n;

int go(int x, int v) {
  //cout << x<< " <- " << v << endl;
  if (r[x] != v) {
    if ((r[x]^v) == 1)
      return false;
    int t = r[x];
    REP (i, n) {
      if (r[i] == t)
        r[i] = v;
      if (r[i] == (t^1))
        r[i] = v^1;
    }
  }

  if (u[x])
    return true;
  u[x] = 1;

  int res = 1;

  REP (i, n)
    if (i!=x && abs(pp[i] - pp[x]) < 5-eps) {

      res &= go(i, v^1);
    }

  return res;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int TT;
  cin >> TT;
  REP (T, TT) {
    int cc = 4;
    printf ("Case #%d: ", T+1);

    cin >> n;

    vector <cfloat> s(n), p(n);

    REP (i, n) {
      string ss;
      cin >> ss >> s[i] >> p[i];

      if (ss == "L")
        r[i] = 2;
      else
        r[i] = 3;
    }

    vector <cfloat> t;
    t.pb (0);

    REP (i, n)
      REP (j, n)
        if (i!=j) {
          if (s[i] == s[j])
            continue;

          cfloat p1 = p[i];
          cfloat p2 = p[j];
          cfloat s1 = s[i];
          cfloat s2 = s[j];

          cfloat t1 = solve(p1+5, s1, p2, s2);
          cfloat t2 = solve(p1, s1, p2+5,s2);
          if (t1>=0)
            t.pb(t1);
          if (t2>=0)
            t.pb(t2);
        }

    SORT(t);
    int tt = t.size();
    REP (i, tt-1)
      t.pb ((t[i]+t[i+1])/2);
    SORT(t);
    t.resize(unique(ALL(t)) - t.begin());

    REP(ii, t.size()-1) {
      REP (i, n)
        pp[i] = p[i]+t[ii]*s[i];
      REP(i, n) {
        bool ok = true;
        REP (j, n)
          if (i!=j)
            if (abs(pp[i] - pp[j]) < 5-eps) {
              //if(i<j) cout << i << " " << j << endl;
              ok = false;
            }
        if (ok) {
          r[i] = cc;
          cc+=2;
        }
      }
      //REP (i, n)
      //  cout << r[i] << endl;

      memset(u, 0, sizeof (u));

      int ok = 1;
      REP (i, n) {
        ok &= go (i, r[i]);
      }

      if (!ok) {
        printf ("%.5Lf\n", t[ii-1]);
        goto next;
      }
    }

    printf("Possible\n");
    next:;
  }

  return 0;
}
