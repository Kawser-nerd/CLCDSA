#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cstdint>
#include <climits>
#include <cfloat>
#include <cmath>

#define XSTR(s) STR(s)
#define STR(s) #s

using namespace std;

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

i64 R, B, x, y;

void input() {
#ifdef DEBUG
  ifstream in(XSTR(INPUT));
#else
  istream &in = cin;
#endif
  in >> R >> B
     >> x >> y;
}

int main() {
  input();
  
  i64 l = 0;
  i64 r = min(R, B);
  
  i64 n = 0;
  while (l <= r) {
    i64 c = (l + r) >> 1;
    if ((R - c) / (x - 1) + (B - c) / (y - 1) >= c) {
      n = c;
      l = c + 1;
    }
    else {
      r = c - 1;
    }
  }
  
  cout << n << endl;
  
  return 0;
}