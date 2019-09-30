#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
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

double P;

void input() {
#ifdef DEBUG
  ifstream in(XSTR(INPUT));
#else
  istream &in = cin;
#endif
  in >> P;
}

double time(double x) {
  return x + P * pow(2, -x / 1.5);
}

int main() {
  input();
  
  double t = 1.5 * log2(P * (log(2) / 1.5));
  
  printf("%.9lf\n", time(max(0., t)));
  
  return 0;
}