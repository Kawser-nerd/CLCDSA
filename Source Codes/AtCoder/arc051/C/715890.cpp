#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>


#define INF 1000000002486618624LL
#define MOD 1000000007
#define ALL(x) std::begin(x), std::end(x)


class log_t {
public:
  log_t(double base) : base_(base), loga_(log(base)) {};

public:
  double operator()(double x) const {
    if (base_ == 1) {
      return x;
    }
    else {
      return log(x) / loga_;
    }
  };

private:
  double base_;
  double loga_;
};


class number_t {
public:
  number_t(double xx, long long yy, int zz = 0) : x(xx), y(yy), z(zz) {};

public:
  inline bool operator>(const number_t& a) const {
    return x > a.x;
  };

public:
  double x;
  long long y;
  int z;
};


long long modpow(long long x, long long y)
{
  long long p = 1;

  for ( ; y; (x *= x) %= MOD, y >>= 1)
    if (y & 1)
      (p *= x) %= MOD;

  return p;
}


int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int N;

  long long A, B, a[55];

  std::cin >> N >> A >> B;

  log_t loga(A);

  int x = std::max((B - 55 * N) / N, 0LL);

  long long M = modpow(A, x);

  std::vector<number_t> aa;

  for (int i = 0; i < N; i ++) {
    std::cin >> a[i];

    aa.emplace_back(loga(a[i]) + x, (a[i] * M) % MOD);
  }

  B -= x * N;

  std::priority_queue<number_t, std::vector<number_t>, std::greater<number_t>> pq;

  for (int i = 0; i < N; i ++)
    pq.push(aa[i]);

  for (int i = 0; i < B; i ++) {
    number_t a = pq.top();

    pq.pop();

    pq.emplace(a.x + 1, (a.y * A) % MOD, a.z + 1);
  }

  while (! pq.empty()) {
    number_t a = pq.top();

    pq.pop();

    std::cout << a.y << std::endl;
  }

  return 0;
}