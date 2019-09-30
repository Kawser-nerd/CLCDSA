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

#define XSTR(s) STR(s)
#define STR(s) #s

using namespace std;

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

i32 x1, y1, r, x2, y2, x3, y3;

void input() {
#ifdef DEBUG
  ifstream in(XSTR(INPUT));
#else
  istream &in = cin;
#endif
  in >> x1
     >> y1
     >> r
     >> x2
     >> y2
     >> x3
     >> y3;
}

i32 dist2(i32 x, i32 y) {
  return (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
}

int main() {
  input();
  
  {
    i32 x_min = x1 - r;
    i32 x_max = x1 + r;
    i32 y_min = y1 - r;
    i32 y_max = y1 + r;
    if (x_min < x2 ||
        x_max > x3 ||
        y_min < y2 ||
        y_max > y3) {
      cout << "YES" << endl;
    }
    else {
      cout << "NO" << endl;
    }
  }
  
  {
    if (dist2(x2, y2) > r * r ||
        dist2(x2, y3) > r * r ||
        dist2(x3, y2) > r * r ||
        dist2(x3, y3) > r * r) {
      cout << "YES" << endl;
    }
    else {
      cout << "NO" << endl;
    }
  }
  
  return 0;
}