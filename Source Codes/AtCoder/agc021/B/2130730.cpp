/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-2-24 21:32:31
 * Powered by Visual Studio Code
 */

#include <iostream>
#include <iomanip>   // << fixed << setprecision(xxx)
#include <algorithm> // do { } while ( next_permutation(A, A+xxx) ) ;
#include <vector>
#include <string> // to_string(nnn) // substr(m, n) // stoi(nnn)
#include <complex>
#include <tuple>
#include <queue>
#include <stack>
#include <map> // if (M.find(key) != M.end()) { }
#include <set>
#include <random> // random_device rd; mt19937 mt(rd());
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define DEBUG 0 // change 0 -> 1 if we need debug.

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

typedef complex<double> P;

bool cmp_x(const P& p, const P& q)
{
  if (p.real() != q.real())
    return p.real() < q.real();
  return p.imag() < q.imag();
}

double det(P p, P q)
{
  return (conj(p) * q).imag();
}

double dot(P p, P q)
{
  return (conj(p) * q).real();
}

double theta(P p, P q)
{
  return arg(q / p);
}

vector<P> convex_hull(P* ps, int n)
{
  sort(ps, ps + n, cmp_x);
  int k = 0;
  vector<P> qs(n * 2);
  for (auto i = 0; i < n; i++)
  {
    while (k > 1 && det(qs[k-1] - qs[k-2], ps[i] - qs[k-1]) <= 0)
      k--;
    qs[k++] = ps[i];
  }
  for (auto i = n-2, t=k; i >= 0; i--)
  {
    while (k > t && det(qs[k-1] - qs[k-2], ps[i] - qs[k-1]) <= 0)
      k--;
    qs[k++] = ps[i];
  }
  qs.resize(k - 1);
  return qs;
}

double kaku(P x, P p, P y)
{
  return theta(y - p, x - p);
}

double PI = 3.1415926535897932384626433832795;

int main()
{
  int N;
  cin >> N;
  P ps[120];
  P ind[120];
  for (auto i = 0; i < N; i++)
  {
    double x, y;
    cin >> x >> y;
    ind[i] = ps[i] = P(x, y);
  }
  vector<P> V = convex_hull(ps, N);
  double ans[120];
  fill(ans, ans + N, 0);
  int M = V.size();
  for (auto i = 0; i < M; i++)
  {
    double prob = (PI - kaku(V[(i-1 + M)%M], V[i], V[i+1])) / (2 * PI);
    for (auto j = 0; j < N; j++)
    {
      if (V[i] == ind[j])
      {
        ans[j] = prob;
      }
    }
  }
  for (auto i = 0; i < N; i++)
  {
    cout << fixed << setprecision(12) << ans[i] << endl;
  }
}