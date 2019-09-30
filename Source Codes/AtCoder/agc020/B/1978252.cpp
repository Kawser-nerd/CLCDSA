#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>


#define INF 4000000000000000000LL
#define MOD 1000000007
#define ALL(x) std::begin(x), std::end(x)


void infeasible()
{
  std::cout << -1 << std::endl;

  exit(0);
}


int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  std::cout << std::fixed << std::setprecision(6);

  int K, A[111111];

  std::cin >> K;

  for (int i = 0; i < K; i ++)
    std::cin >> A[i];

  if (A[K - 1] != 2)
    infeasible();

  long long l = 2, u = 2;

  for (int i = K - 1; i >= 0; i --) {
    long long ll = (l + A[i] - 1) / A[i] * A[i], uu = u / A[i] * A[i] + A[i] - 1;

    if (ll > u)
      infeasible();

    l = ll;
    u = uu;
  }

  std::cout << l << ' ' << u << std::endl;

  return 0;
}