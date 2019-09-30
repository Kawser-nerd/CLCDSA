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

string S;

void input() {
#ifdef DEBUG
  ifstream in(XSTR(INPUT));
#else
  istream &in = cin;
#endif
  in >> S;
}

int main() {
  input();
  
  sort(S.begin(), S.end());
  vector<i32> counts;
  counts.reserve(S.length());
  char prev = 0;
  for (auto c : S) {
    if (prev >= 'a' && prev <= 'z' && prev == c) {
      counts.back()++;
    }
    else {
      counts.push_back(1);
    }
    prev = c;
  }
  i32 odd = 0;
  i32 pair = 0;
  for (auto count : counts) {
    odd += count & 1;
    pair += count >> 1;
  }
  
  if (odd) {
    cout << 1 + 2 * (pair / odd) << endl;
  }
  else {
    cout << 2 * pair << endl;
  }
  
  
  return 0;
}