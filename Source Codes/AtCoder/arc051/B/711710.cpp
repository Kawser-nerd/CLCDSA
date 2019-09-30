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
#include <functional>

#define XSTR(s) STR(s)
#define STR(s) #s

using namespace std;

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

i32 K;

void input() {
#ifdef DEBUG
  ifstream in(XSTR(INPUT));
#else
  istream &in = cin;
#endif
  in >> K;
}

i32 count(i32 a, i32 b) {
  i32 counter = 0;
  function<i32(i32, i32)> gcd = [&](i32 a, i32 b) -> i32 {
    if (b == 0) return a;
    counter++;
    return gcd(b, a%b);
  };
  gcd(a, b);
  return counter;
}

int main() {
  input();
  i32 a = 2;
  i32 b = 1;
  for (i32 i = 0; i < K - 1; i++) {
    if (a > b) {
      b += a;
    }
    else {
      a += b;
    }
  }
  if (b > a) {
    swap(a, b);
  }
  cout << a << ' ' << b << endl;
  return 0;
}