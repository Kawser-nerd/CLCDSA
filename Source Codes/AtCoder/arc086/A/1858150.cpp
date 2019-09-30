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

  int K, N, A;

  std::cin >> N >> K;

  std::map<int, int> map;

  for (int i = 0; i < N; i ++) {
    std::cin >> A;

    map[A] ++;
  }

  if (map.size() <= K) {
    std::cout << 0 << std::endl;
  }
  else {

    std::vector<int> a;

    for (const auto& kv : map)
      a.push_back(kv.second);

    std::sort(ALL(a));

    std::cout << std::accumulate(std::begin(a), std::end(a) - K, 0LL) << std::endl;
  }

  return 0;
}