/* GCJ'08
 * Author: Per Austrin
 */
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;
#define dprintf debug && printf
bool debug = false;

void init() {
}


const double undefined = 1.0/0.0;
const double eps = 1e-12;

// Overkill FTW!
template <int N> int
solve_linear(int n, double A[N][N], double b[N], double x[N]) {
  int row[N], col[N], undef[N], invrow[N], invcol[N], rank = 0;
  for (int i = 0; i < n; ++i)
    row[i] = col[i] = i, undef[i] = false;
  
  for (int i = 0; i < n; rank = ++i) {
    int br = i, bc = i;
    double v, bv = abs(A[row[i]][col[i]]);
    for (int r = i; r < n; ++r)
      for (int c = i; c <= n; ++c)
	if ((v = abs(A[row[r]][col[c]])) > bv)
	  br = r, bc = c, bv = v;
    if (bv < eps) break;
    bv = A[row[br]][col[bc]];
    if (i != br) row[i] ^= row[br] ^= row[i] ^= row[br];
    if (i != bc) col[i] ^= col[bc] ^= col[i] ^= col[bc];
    for (int j = i + 1; j < n; ++j) {
      double fac = A[row[j]][col[i]] / bv;
      A[row[j]][col[i]] = 0;
      b[row[j]] -= fac * b[row[i]];
      for (int k = i + 1; k < n; ++k)
	A[row[j]][col[k]] -= fac * A[row[i]][col[k]];
    }
  }

  for (int i = rank; i-- ; ) {
    b[row[i]] /= A[row[i]][col[i]];
    A[row[i]][col[i]] = 1;
    for (int j = rank; j < n; ++j)
      if (abs(A[row[i]][col[j]]) > eps)
	undef[i] = true;
    for (int j = i - 1; j >= 0; --j) {
      if (undef[i] && abs(A[row[j]][col[i]]) > eps)
	undef[j] = true;
      else {
	b[row[j]] -= A[row[j]][col[i]] * b[row[i]];
	A[row[j]][col[i]] = 0;
      }
    }
  }

  for (int i = 0; i < n; ++i)
    invrow[row[i]] = i, invcol[col[i]] = i;
  for (int i = 0; i < n; ++i)
    if (invrow[i] >= rank || undef[invrow[i]]) b[i] = undefined;
  for (int i = 0; i < n; ++i) x[i] = b[row[invcol[i]]];
  return rank;
}


void solve(int P) {

  double A[10][10], B[10];

  int px1, py1, px2, py2, px3, py3;
  int qx1, qy1, qx2, qy2, qx3, qy3;
  scanf("%d%d%d%d%d%d", &px1, &py1, &px2, &py2, &px3, &py3);
  scanf("%d%d%d%d%d%d", &qx1, &qy1, &qx2, &qy2, &qx3, &qy3);

  if ((py2-py1)*(px3-px1)-(py3-py1)*(px2-px1) == 0) {
    assert(0);
  }

  memset(A, 0, sizeof(A));

  A[0][0] = px1; A[0][1] = py1; A[0][4] = 1;
  A[1][2] = px1; A[1][3] = py1; A[1][5] = 1;
  A[2][0] = px2; A[2][1] = py2; A[2][4] = 1;
  A[3][2] = px2; A[3][3] = py2; A[3][5] = 1;
  A[4][0] = px3; A[4][1] = py3; A[4][4] = 1;
  A[5][2] = px3; A[5][3] = py3; A[5][5] = 1;

  B[0] = qx1;
  B[1] = qy1;
  B[2] = qx2;
  B[3] = qy2;
  B[4] = qx3;
  B[5] = qy3;

  double x[10];

  assert(solve_linear<10>(6, A, B, x) == 6);

  assert(fabs(x[0]*px1 + x[1]*py1 + x[4] - qx1) < 1e-9);
  assert(fabs(x[2]*px1 + x[3]*py1 + x[5] - qy1) < 1e-9);
  assert(fabs(x[0]*px2 + x[1]*py2 + x[4] - qx2) < 1e-9);
  assert(fabs(x[2]*px2 + x[3]*py2 + x[5] - qy2) < 1e-9);
  assert(fabs(x[0]*px3 + x[1]*py3 + x[4] - qx3) < 1e-9);
  assert(fabs(x[2]*px3 + x[3]*py3 + x[5] - qy3) < 1e-9);

  dprintf("trans is:\n");
  dprintf(" (%lf %lf) + (%lf)\n",
	  x[0], x[1], x[4]);
  dprintf(" (%lf %lf) + (%lf)\n",
	  x[2], x[3], x[5]);

  double a[2][2], b[2];
  a[0][0] = -x[0]+1;
  a[0][1] = -x[1];
  a[1][0] = -x[2];
  a[1][1] = -x[3]+1;
  b[0] = x[4];
  b[1] = x[5];
  double ans[2];

  dprintf("new sys:\n");
  dprintf(" (%lf %lf) = (%lf)\n",
	  a[0][0], a[0][1], b[0]);
  dprintf(" (%lf %lf) = (%lf)\n",
	  a[1][0], a[1][1], b[1]);

  assert(solve_linear<2>(2, a, b, ans) == 2);
  assert(fabs((x[0]-1)*ans[0] + (x[1])*ans[1]+x[4]) < 1e-9);
  assert(fabs(x[2]*ans[0] + (x[3]-1)*ans[1]+x[5]) < 1e-9);

  printf("Case #%d: %.9lf %.9lf\n", P, ans[0], ans[1]);
}

int main() {
  int n;
  scanf("%d", &n);
  init();
  for (int i = 1; i <= n; ++i) solve(i);
  return 0;
}
