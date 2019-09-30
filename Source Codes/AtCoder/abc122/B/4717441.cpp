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

  std::string s;

  std::cin >> s;

  int cp = 0;

  for (int i = 0, c = 0, size = s.size(); i < size; i ++)
    if (strchr("ACTG", s[i])) {
      cp = std::max(++ c, cp);
    }
    else {
      c = 0;
    }

  std::cout << cp << std::endl;
  
  return 0;
}