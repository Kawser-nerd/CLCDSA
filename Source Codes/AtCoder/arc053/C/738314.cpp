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

i64 N;
vector<i64> a1, b1, a2, b2;
i64 eq = 0;

void input() {
#ifdef DEBUG
  ifstream in(XSTR(INPUT));
#else
  istream &in = cin;
#endif
  in >> N;
  a1.reserve(N); b1.reserve(N);
  a2.reserve(N); b2.reserve(N);
  for (i64 i = 0; i < N; i++) {
    i64 a, b;
    in >> a >> b;
    if (a < b) {
      a1.push_back(a);
      b1.push_back(b);
    }
    else if (a > b) {
      a2.push_back(a);
      b2.push_back(b);
    }
    else {
      if (eq < a) {
        eq = a;
      }
    }
  }
}

bool compare1(const i64 i, const i64 j) {
//  if (a1[i] == a1[j]) {
//    return b1[i] > b1[j];
//  }
//  return a1[i] < a1[j];
  return max(a1[i], a1[i] - b1[i] + a1[j]) < max(a1[j], a1[j] - b1[j] + a1[i]);
}

bool compare2(const i64 i, const i64 j) {
//  if (a2[i] == a2[j]) {
//    return b2[i] > b2[j];
//  }
//  return a2[i] > a2[j];
  return max(a2[i], a2[i] - b2[i] + a2[j]) < max(a2[j], a2[j] - b2[j] + a2[i]);
}

int main() {
  input();
  
  vector<i64> indexes1(a1.size());
  iota(indexes1.begin(), indexes1.end(), 0);
  sort(indexes1.begin(), indexes1.end(), compare1);
  
  vector<i64> indexes2(a2.size());
  iota(indexes2.begin(), indexes2.end(), 0);
  sort(indexes2.begin(), indexes2.end(), compare2);
  
  i64 ans = 0;
  i64 current = 0;
  for (auto i : indexes1) {
    current += a1[i];
    if (ans < current) {
      ans = current;
    }
    current -= b1[i];
  }
  
  if (ans < current + eq) {
    ans = current + eq;
  }
  
  for (auto i : indexes2) {
    current += a2[i];
    if (ans < current) {
      ans = current;
    }
    current -= b2[i];
  }
  
  cout << ans << endl;
  
  return 0;
}