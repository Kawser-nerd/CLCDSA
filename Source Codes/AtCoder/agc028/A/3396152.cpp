#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <bitset>
#include <unordered_map>
#include <tuple>
#include <utility>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <sys/time.h>

using namespace std;


long long lcm(long long a, long long b ) {
  long long x = a*b;

  if (a < b) {
    long long t = a;
    a = b;
    b = t;
  }

  long long r = a % b;
  while (r > 0) {
    a = b;
    b = r;
    r = a % b;
  }
  return x/b;
}//lcm

void solve(long long N, long long M, string S, string T){
  long long ret = lcm(N, M);
  for (int i = 0; i < N; i++) {
    if ((i*(ret/N) % (ret/M) != 0) || (i*(ret/N) / (ret/M) > M-1)) {
      continue;
    }
    if (S[i] != T[i*(ret/N) / (ret/M)]) {
        std::cout << -1 << std::endl;
        return;
    }
  }
  std::cout << ret << std::endl;
  return;
}

int main(){
  string T;
  string S;
  long long N;
  long long M;
  scanf("%lld",&N);
  scanf("%lld",&M);
  cin >> S;
  cin >> T;
  solve(N, M, S, T);
  return 0;
}