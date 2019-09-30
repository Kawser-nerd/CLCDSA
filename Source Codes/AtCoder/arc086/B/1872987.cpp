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

  int N, a[55];

  std::cin >> N;

  for (int i = 0; i < N; i ++)
    std::cin >> a[i];

  auto pair = std::minmax_element(a, a + N);

  std::vector<std::pair<int, int>> pairs;

  if (std::abs(*pair.first) > std::abs(*pair.second)) {
    for (int i = 0; i < N; i ++)
      if (a[i] != *pair.first) {
        pairs.emplace_back(pair.first - a, i);
        
        a[i] += *pair.first;
      }

    for (int i = N - 1; i >= 1; i --) {
      pairs.emplace_back(i, i - 1);

      a[i - 1] += a[i];
    }
  }
  else {
    for (int i = 0; i < N; i ++)
      if (a[i] != *pair.second) {
        pairs.emplace_back(pair.second - a, i);
        
        a[i] += *pair.second;
      }

    for (int i = 0; i < N - 1; i ++) {
      pairs.emplace_back(i, i + 1);

      a[i + 1] += a[i];
    }
  }

  std::cout << pairs.size() << std::endl;

  for (const auto& pair : pairs)
    std::cout << pair.first + 1 << ' ' << pair.second + 1 << std::endl;

  return 0;
}