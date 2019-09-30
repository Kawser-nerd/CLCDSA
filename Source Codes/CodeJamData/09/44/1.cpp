#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
using namespace std;

#define all(c) ((c).begin()), ((c).end()) 
#define iter(c) __typeof((c).begin())
#define present(c, e) ((c).find((e)) != (c).end()) 
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)

typedef long long ll;

int readint() { 
  int i, j, s;
  while (!isdigit(i = getchar()) && i != '-');
  if (i == '-') { s = -1; j = 0; }
  else { s = 1; j = i - '0'; }
  while (isdigit(i = getchar())) j = ((j << 1) + (j << 3) + (i - '0'));
  return j * s;
}


#include <complex>
const double EPS = 1e-8;
typedef complex<double> p_t;

void cross_c_c(const p_t &c, const double &r, const p_t &d, const double &s,
               vector<p_t> &res) {
  double di = abs(c - d);
  res.clear();
  if (di > r + s || di < abs(r - s)) return;
  double l = ((r * r - s * s) / di + di) / 2.0, n = sqrt(r * r - l * l);
  p_t e = c + (d - c) * l / di, p = (d - c) * n / di * p_t(0.0, -1.0);
  res.pb(e + p); res.pb(e - p);
}

int N;
p_t P[50];
double R[50];
int wtr[50];

void saiki(double rad, int d) {
  rep (i, N) if (!wtr[i]) goto notyet;
  throw "done!";
 notyet:
  if (d == 2) return;

  // 2つ以上覆う
  vector<p_t> cand;  
  rep (i, N) {
    if (wtr[i]) continue;

    rep (j, i) {
      if (wtr[j]) continue;

      cross_c_c(P[i], rad - R[i], P[j], rad - R[j], cand);
      rep (c, cand.size()) {
        const p_t &q = cand[c];
        bool tmp[50];
        rep (k, N) tmp[k] = !wtr[k] && (abs(P[k] - q) < rad - R[k] + EPS);

        rep (k, N) if (tmp[k]) wtr[k]++;
        if (d > 0 || wtr[0]) saiki(rad, d + 1);
        rep (k, N) if (tmp[k]) wtr[k]--;
      }
    }
  }

  // 1つだけ覆う
  rep (i, N) {
    if (wtr[i]) continue;

    if (d > 0 || i == 0) {
      wtr[i]++;
      saiki(rad, d + 1);
      wtr[i]--;
    }    
  }
}

int main() {
  int cases = readint();
  rep (ca, cases) {
    fprintf(stderr, "%d / %d\n", ca, cases);
    
    N = readint();
    rep (i, N) {
      P[i].real() = readint();
      P[i].imag() = readint();
      R[i] = readint();
    }

    double lb = 0.0, ub = 3000;
    rep (i, N) lb = max(lb, R[i]);

    rep (itn, 35) {
      double md = (lb + ub) / 2.0;

      rep (i, N) wtr[i] = 0;
      try {
        saiki(md, 0);
        lb = md; // ng
      } catch(...) {
        ub = md; // ok
      }
    }

    printf("Case #%d: %.10f\n", ca + 1, (lb + ub) / 2.0);
  }

  return 0;
}
