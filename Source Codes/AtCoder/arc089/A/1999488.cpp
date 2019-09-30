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


int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  std::cout << std::fixed << std::setprecision(6);

  int N, t, x, y, tt = 0, xx = 0, yy = 0;

  std::cin >> N;

  for (int i = 0; i < N; i ++) {
    std::cin >> t >> x >> y;

    int d = std::abs(x - xx) + std::abs(y - yy), dt = t - tt;

    if (! (d <= dt && (d - dt) % 2 == 0)) {
      std::cout << "No" << std::endl;

      return 0;
    }

    tt = t;
    xx = x;
    yy = y;
  }

  std::cout << "Yes" << std::endl;

  return 0;
}