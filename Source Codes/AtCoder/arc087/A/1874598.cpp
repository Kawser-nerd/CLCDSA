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

  int N, a;

  std::map<int, int> map;

  std::cin >> N;

  for (int i = 0; i < N; i ++) {
    std::cin >> a;

    map[a] ++;
  }

  int c = 0;

  for (const auto& kv : map) {
    if (kv.second < kv.first) {
      c += kv.second;
    }
    else {
      c += kv.second - kv.first;
    }
  }

  std::cout << c << std::endl;

  return 0;
}