#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>


#define INF 1000000002486618624LL
#define MOD 1000000007
#define ALL(x) std::begin(x), std::end(x)


int counter = 0;

int gcd(int a, int b) {
  if (b == 0)
    return a;

  std::cerr << "gcd: a=" << a << " b=" << b << std::endl;
    
  counter ++;
    
  return gcd(b, a % b);
}


int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int K, a = 1, b = 1;

  std::cin >> K;

  for (int i = 0; i < K; i ++) {
    int aa = a + b, bb = a;

    a = aa;
    b = bb;

    std::cerr << "  i=" << i << " a=" << a << " b=" << b << std::endl;
  }

  std::cout << a << ' ' << b << std::endl;

  gcd(a, b);

  std::cerr << "K=" << K << " counter=" << counter << std::endl;

  assert(K == counter);
  
  return 0;
}