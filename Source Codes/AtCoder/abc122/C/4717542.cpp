#include <algorithm>
#include <array>
#include <bitset>
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
  std::cerr << std::fixed << std::setprecision(6);

  int N, Q, l, r, a[111111] = {0}, acc[111111];

  std::string s;

  std::cin >> N >> Q >> s;

  for (int i = 0; i < N - 1; i ++)
    if (s[i] == 'A' && s[i + 1] == 'C')
      a[i] = 1;

  acc[0] = 0;

  for (int i = 0; i < N; i ++)
    acc[i + 1] = a[i] + acc[i];

  for (int i = 0; i < Q; i ++) {
    std::cin >> l >> r;

    if (a[r - 1]) {
      std::cout << acc[r] - acc[l - 1] - 1 << std::endl;
    }
    else {
      std::cout << acc[r] - acc[l - 1] << std::endl;
    }
  }
  
  return 0;
}