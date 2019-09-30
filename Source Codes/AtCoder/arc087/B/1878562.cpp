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


#define H 0
#define V 1


bool feasible(const int x, const std::vector<int>& a)
{
  if (a.empty())
    return x == 0;
  
  bool dp[2][20000], *curr = dp[0], *next = dp[1];

  memset(dp, 0, sizeof(dp));

  curr[10000] = true;

  for (const auto& i : a) {
    memset(next, 0, sizeof(dp[0]));
    
    for (int j = 0; j < 20000; j ++)
      if (curr[j]) {
        assert(0 <= j - i && j + i < 20000);
        
        next[j - i] = next[j + i] = true;
      }

    std::swap(curr, next);
  }

  return curr[x + 10000];
}


int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  std::cout << std::fixed << std::setprecision(6);

  std::string s;

  int x, y, size;

  std::cin >> s >> x >> y;

  size = s.size();

  std::reverse(ALL(s));

  while (! s.empty()) {
    char c = s.back();

    if (c == 'T')
      break;

    x --;

    s.pop_back();
  }

  int d = H;

  std::vector<int> h, v;

  while (! s.empty()) {
    char c = s.back();

    int n = 1;

    s.pop_back();

    while (! s.empty() && s.back() == c) {
      s.pop_back();

      n ++;
    }

    if (c == 'T') {
      if (n % 2)
        d = 1 - d;
    }
    else {
      (d == H ? h : v).push_back(n);
    }
  }

  std::cout << (feasible(x, h) && feasible(y, v) ? "Yes" : "No") << std::endl;

  return 0;
}