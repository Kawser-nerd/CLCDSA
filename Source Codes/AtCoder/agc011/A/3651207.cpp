#include <iostream>
#include <map>
using namespace std;
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

int main() {
  int N, C, K; scanf("%d%d%d", &N, &C, &K);
  map<int, int>T;
  int t;
  for (int i{0}; i < N; ++i) {
    scanf("%d", &t); ++T[t];
  }

  int total{0};

  for (auto& kv : T) {
    int temp = kv.second; kv.second = 0;
    if (temp % C != 0) {
      decltype(T)::iterator it = T.lower_bound(kv.first + 1);
      decltype(T)::iterator last = T.upper_bound(kv.first + K);
      while (it != last) {
        int add = MIN(C - temp % C, it->second);
        temp += add; it->second -= add;
        if (temp % C == 0) break;
        ++it;
      }
    }
    total += (temp + (C - 1)) / C;
  }

  printf("%d\n", total);
  return 0;
}