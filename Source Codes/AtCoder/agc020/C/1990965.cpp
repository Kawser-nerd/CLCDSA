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

  int N, A[2222];

  std::cin >> N;

  for (int i = 0; i < N; i ++)
    std::cin >> A[i];

  if (N == 1) {
    std::cout << A[0] << std::endl;
  }
  else {
    std::bitset<4444444> bitset;

    bitset.set(0);

    for (int i = 0; i < N; i ++)
      bitset |= bitset << A[i];

    int S = std::accumulate(A, A + N, 0);

    for (int i = (S + 1) / 2; i <= S; i ++)
      if (bitset[i]) {
        std::cout << i << std::endl;

        break;
      }
  }

  return 0;
}