/* GCJ'08
 * Author: Per Austrin
 */
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <algorithm>
//#include <string>
//#include <map>
//#include <vector>

using namespace std;
#define dprintf debug && printf
bool debug = false;

typedef pair<int, int > pii;

void init() {
}

const int P = 10007;

template <class Z> Z euclid(Z a, Z b, Z &x, Z &y) {
  if (b) {  Z d = euclid(b, a % b, y, x);
            return y -= a/b * x, d;  }
  return x = 1, y = 0, a;
}

int inv(int n) {
  n %= P;
  int x, y;
  euclid(n, P, x, y);
  while (x < 0) x += P;
  while (x >= P) x -= P;
  return x;
}

int facoccs(int n) {
  long long p = P;
  int res = 0;
  while (p <= n) res += n / p, p *= P;
  return res;
}

int choose0(int n, int k) {
  int ret = 1;
  if (facoccs(n) - facoccs(k) - facoccs(n-k) > 0) return 0;
  if (k > n-k) k = n-k;
  for (int i = 1; i <= k; ++i) {
    (ret *= n+1-i) %= P;
    (ret *= inv(i)) %= P;
  }
  return ret;
}

int choose(int n, int k) {
  if (facoccs(n) - facoccs(k) - facoccs(n-k) > 0) return 0;
  int ret = 1;
  while (k) {
    ret *= choose0(n % P, k % P);
    n /= P;
    k /= P;
  }
  return ret;
}


int J(int x, int y) {
  if ((2*x-y) % 3 != 0 || (2*y-x) % 3 != 0) return 0;
  int n1 = (2*y-x)/3, n2 = (2*x-y)/3;
  if (n1 < 0 || n2 < 0) return 0;
  return choose(n1+n2, n1);
}

void solve(int PP) {

  pii bad[20];
  int W, H, R;
  scanf("%d%d%d", &W, &H, &R);

  for (int i = 0; i < R; ++i)
    scanf("%d%d", &bad[i].first, &bad[i].second);

  sort(bad, bad + R);
  int res = 0;
  for (int S = 0; S < (1<<R); ++S) {
    int sgn = 1, add = 1;
    int x = 1, y = 1;
    for (int i = 0; i < R; ++i) {
      if (S & (1<<i)) {
	if (bad[i].first < x || bad[i].second < y) {
	  add = 0; 
	  break;
	}
	//	printf("(%d %d)-> (%d,%d) -> %d\n",	       x, y, bad[i].first, bad[i].second, J(bad[i].first-x, bad[i].second-y));
	(add *= J(bad[i].first-x, bad[i].second-y)) %= P;
	sgn = -sgn;
	x = bad[i].first;
	y = bad[i].second;
      }
    }
    (add *= J(W-x, H-y)) %= P;
    //    printf("went S %d -> add %d\n", S, add);
    if (sgn > 0) (res += add) %= P;
    else (res += P-add) %= P;
  }
  assert(0 <= res && res < P);
  printf("Case #%d: %d\n", PP, res);
}

int main() {
  int n;
  scanf("%d", &n);
  init();
  for (int i = 1; i <= n; ++i) solve(i);
  return 0;
}
