#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <climits>

using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define rem (x) x % 1000000007;

#define fillInt(xs, x)        \
  for (int i = 0; i < x; i++) \
    scanf("%d", &xs[i]);
#define fillLong(xs, x)       \
  for (int i = 0; i < x; i++) \
    scanf("%ld", &xs[i]);
#define sortv(xs) sort(S.begin(), S.end());
#define lbv(xs, x) lower_bound(xs.begin(), xs.end(), x) - xs.begin();
#define ubv(xs, x) upper_bound(xs.begin(), xs.end(), x) - xs.begin();

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int A, B, Q;
  cin >> A >> B >> Q;

  vector<long> S(A), T(B), X(Q);
  fillLong(S, A);
  fillLong(T, B);
  fillLong(X, Q);

  sortv(S);
  sortv(T);

  for (int i = 0; i < X.size(); i++)
  {
    long x = X[i];
    long m = 1000000000000;

    int s = lbv(S, x);

    if (s != 0)
    {
      long s1 = S[s - 1];
      int t1 = lbv(T, s1);
      long t11 = T[max(t1 - 1, 0)];
      long t12 = T[min(t1, B - 1)];

      m = min(
          abs(s1 - x) + abs(t11 - s1),
          m);
      m = min(
          abs(s1 - x) + abs(t12 - s1),
          m);
    }

    if (s != A)
    {
      long s2 = S[s];
      int t2 = lbv(T, s2);
      long t21 = T[max(t2 - 1, 0)];
      long t22 = T[min(t2, B - 1)];

      m = min(
          abs(s2 - x) + abs(t21 - s2),
          m);
      m = min(
          abs(s2 - x) + abs(t22 - s2),
          m);
    }

    int t = lbv(T, x);

    if (t != 0)
    {
      long t1 = T[t - 1];
      int s1 = lbv(S, t1);
      long s11 = S[max(s1 - 1, 0)];
      long s12 = S[min(s1, A - 1)];

      m = min(
          abs(t1 - x) + abs(s11 - t1),
          m);
      m = min(
          abs(t1 - x) + abs(s12 - t1),
          m);
    }

    if (t != B)
    {
      long t2 = T[t];
      int s2 = lbv(S, t2);
      long s21 = S[max(s2 - 1, 0)];
      long s22 = S[min(s2, A - 1)];

      m = min(
          abs(t2 - x) + abs(s21 - t2),
          m);
      m = min(
          abs(t2 - x) + abs(s22 - t2),
          m);
    }

    printf("%ld\n", m);
  }
  return 0;
}