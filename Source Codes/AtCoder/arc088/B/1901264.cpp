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

  std::string s;

  std::cin >> s;

  int size = s.size(), acc[111111];

  acc[0] = 0;

  for (int i = 0; i < size; i ++)
    acc[i + 1] = acc[i] + (s[i] - '0');

  int l, r;

  for (l = 0, r = size; l < r; l ++, r --) {
    int c = acc[r] - acc[l];
    
    if (c == 0 || c == r - l) {
      std::cout << r << std::endl;

      return 0;
    }
  }

  assert(l == (size + 1) / 2);

  std::cout << l << std::endl;

  return 0;
}