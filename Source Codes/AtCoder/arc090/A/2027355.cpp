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

  int N, A[2][111];

  std::cin >> N;

  for (int i = 0; i < 2; i ++)
    for (int j = 0; j < N; j ++)
      std::cin >> A[i][j];

  int sp = 0;
  
  for (int i = 0; i < N; i ++) {
    int s = 0;

    for (int j = 0; j <= i; j ++)
      s += A[0][j];

    for (int j = i; j < N; j ++)
      s += A[1][j];

    sp = std::max(s, sp);
  }

  std::cout << sp << std::endl;

  return 0;
}