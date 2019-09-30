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

const double EPS = 1E-9;

typedef double number;
 
#define ABS(x) (fabs(x))
#define IS0(x) ((x) < EPS)
#define INV(x) (1 / (x))
#define NOR(x) (x)

typedef vector<number> vec_t;
typedef vector<vec_t> mat_t;

/*
vec_t gauss_jordan(mat_t A, const vec_t &b) { 
  int m = A.size(), n = A[0].size(); // m(tate) x n(yoko)
  for (int i = 0; i < m; i++) A[i].resize(n + 1, b[i]);
 
  int pi = 0;
  for (int pj = 0; pj < n && pi < m; pj++) {
    for (int i = pi + 1; i < m; i++) 
      if (ABS(A[pi][pj]) < ABS(A[i][pj])) swap(A[pi], A[i]);
    if (IS0(A[pi][pj])) continue;
    for (int j = n; j >= pj; j--) 
      A[pi][j] = NOR(A[pi][j] * INV(A[pi][pj]));
    for (int i = 0; i < m; i++) {
      if (i != pi) {
        for (int j = n; j >= pj; j--) A[i][j] = NOR(A[i][j] - A[i][pj] * A[pi][j]);
      }
    }
    pi++;
  }
 
  vec_t x(n, 0);
  for (int i = 0; i < m; i++) {
    int j;
    for (j = 0; j < n; j++) if (!IS0(A[i][j])) break;
    if (j == n && !IS0(A[i][n])) return vec_t(); // 解不能
    else if (j < n) x[j] = A[i][n];
  }
  return x;
}
*/

vector<double> gauss_jordan(mat_t A, const vector<double>& b) {
  int n = A.size();
  for (int i = 0; i < n; i++) A[i].resize(n + 1, b[i]);
  for (int k = 0; k < n; k++) {
    int piv = k;
    for (int i = k + 1; i < n; i++)
      if (ABS(A[i][k]) > ABS(A[piv][k])) piv = i;
    swap(A[k], A[piv]);
 
    for (int i = n; i >= k; i--) A[k][i] /= A[k][k];
    for (int i = 0; i < n; i++) {
      if (i == k) continue;
      for (int j = n; j >= k; j--) A[i][j] -= A[i][k] * A[k][j];
    }
  }
  vector<double> x;
  for (int i = 0; i < n; i++) x.push_back(A[i][n]);
  return x;
}



double comb(int n, int k) {
  double res = 1.0;
  rep (i, k) res *= (n - i) / (double)(k - i);
  return res;
}


int main() {
  int cases = readint();
  rep (ca, cases) {
    int C = readint();
    int N = readint();
    
    mat_t A(C + 2, C + 2);
    vec_t b(C + 2);

    // 行列つくるお
    rep (i, C) {
      // 今 i 枚持ってる気持ちになる
      A[i][i] = -1.0;
      A[i][C + 1] = 1.0;
      b[i] = 0.0;
      
      rep (k, N + 1) {
        // k 枚かぶるお・・・
        int j = i + N - k;
        if (k > i || C < j) continue;
        
        // k 枚かぶる確率
        double p = comb(i, k) * comb(C - i, N - k) / comb(C, N);
        A[i][j] += p;
        // printf("%d->%d: %lf\n", i, j, p);
      }
    }
  
    // C 枚持ってたらもう終わり
    A[C][C] = 1.0;
    b[C] = 0.0;

    // 定数
    A[C + 1][C + 1] = 1.0;
    b[C + 1] = 1.0;

    /*
    rep (i, C + 2) {
      rep (j, C + 2) printf("%.3f ", A[i][j]); puts("");
    }
    */
    // puts("hoge");

    vec_t x = gauss_jordan(A, b);
    // puts("piyo");
    //printf("sz=%d\n", x.size());
    //rep (i, x.size()) printf("%lf ", x[i]); puts("");
    printf("Case #%d: %.10f\n", ca + 1, x[0]);
  }
}
