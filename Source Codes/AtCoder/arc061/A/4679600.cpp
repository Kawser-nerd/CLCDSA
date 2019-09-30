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

#define amari (x) x % 1000000007;

#define fillInt(xs, x)        \
  for (int i = 0; i < x; i++) \
    scanf("%d", &xs[i]);
#define fillLong(xs, x)       \
  for (int i = 0; i < x; i++) \
    scanf("%ld", &xs[i]);
#define sortv(xs) sort(xs.begin(), xs.end());
#define sortvdi(xs) sort(xs.begin(), xs.end(), std::greater<int>());
#define lbv(xs, x) lower_bound(xs.begin(), xs.end(), x) - xs.begin();
#define ubv(xs, x) upper_bound(xs.begin(), xs.end(), x) - xs.begin();

long calc(string h, string rem, long res) {
  if (rem.empty() && h.empty()) return res;
  if (rem.empty()) return 0;
  string newH = h + rem.substr(0, 1);
  string newRem = rem.substr(1);
  long left =  calc("", newRem, res + stol(newH));
  long right = calc(newH, newRem, res);
  return left + right;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string S;
  cin >> S;

  printf("%ld", calc("", S, 0L));
  
  return 0;
}