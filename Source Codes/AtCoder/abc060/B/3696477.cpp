//#include <algorithm>
//#include <cassert>
//#include <cfloat>
//#include <cmath>
//#include <cstdio>
//#include <cstdlib>
//#include <deque>
#include <iostream>
//#include <limits>
//#include <map>
//#include <queue>
//#include <set>
//#include <stack>
//#include <string>
//#include <tuple>
//#include <unordered_map>
//#include <unordered_set>
//#include <vector>
using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

#define DIVUP(x, y) (((x) + ((y) - 1)) / (y))
#define DIVOFF(x, y) (((x) + ((y) / 2)) / (y))
#define REMAINDER(x, y) ((x) % (y))

int main() {
  int A, B, C; scanf("%d%d%d", &A, &B, &C);
  bool judge{};
  for (int i{1}; i < B; ++i) {
    if (A * i % B == C) {
      judge = true;
      break;
    }
  }

  printf("%s\n", judge ? "YES" : "NO");
  return 0;
}