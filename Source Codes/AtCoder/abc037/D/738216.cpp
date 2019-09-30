#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
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

#define MOD 1000000007

// (a + b) % d
u32 modadd(u32 a, u32 b, u32 d) {
  if (a >= d) {
    a %= d;
  }
  if (b >= d) {
    b %= d;
  }
  u64 ans = u64(a) + u64(b);
  ans %= d;
  return u32(ans);
}

// (a * b) % d
u32 modmult(u32 a, u32 b, u32 d) {
  if (a >= d) {
    a %= d;
  }
  if (b >= d) {
    b %= d;
  }
  if (a == 0 || b == 0) {
    return 0;
  }
  u64 res;
  if (a >= d / b) {
    u64 upper = a >> 16;
    u64 lower = a & 0xFFFF;
    u64 x = ((b * upper) % d) << 16;
    u64 y = b * lower;
    res = (x + y) % d;
  }
  else {
    res = a * b;
  }
  return u32(res);
}

// (a ^ b) % d
u32 modpow(u32 a, u32 b, u32 d) {
  u64 res = 1;
  while (b) {
    if (b & 1) {
      res = res * a % d;
    }
    a *= a % d;
    b >>= 1;
  }
  return u32(res);
}

i32 H, W;
vector<u32> a;
vector<u32> path;

void input() {
#ifdef DEBUG
  ifstream in(XSTR(INPUT));
#else
  istream &in = cin;
#endif
//  in >> H >> W;
  scanf("%d %d", &H, &W);
  u64 size = H * W;
  a.resize(size);
  path.resize(size);
  for (u64 i = 0; i < size; i++) {
    scanf("%d", &a[i]);
//    in >> a[i];
    path[i] = 0;
  }
}

u32 at(i32 i, i32 j) {
  return a[i * W + j];
}

u32 paths(i32 i, i32 j) {
  if (path[i * W + j]) {
    return path[i * W + j];
  }
  u32 u = (i > 0 && at(i - 1, j) > at(i, j)) ? paths(i - 1, j) : 0;
  u32 d = (i < H - 1 && at(i + 1, j) > at(i, j)) ? paths(i + 1, j) : 0;
  u32 l = (j > 0 && at(i, j - 1) > at(i, j)) ? paths(i, j - 1) : 0;
  u32 r = (j < W - 1 && at(i, j + 1) > at(i, j)) ? paths(i, j + 1) : 0;
  path[i * W + j] = modadd(modadd(modadd(u, d, MOD), modadd(l, r, MOD), MOD), 1, MOD);
  return path[i * W + j];
}

bool compare(u64 i, u64 j) {
  return a[i] > a[j];
}

int main() {
  input();

  i32 size = W * H;
  vector<i32> index(size);
  iota(index.begin(), index.end(), 0);
  sort(index.begin(), index.end(), compare);
  u32 sum = 0;
  for (i32 k = 0; k < size; k++) {
    i32 i = index[k] / W;
    i32 j = index[k] % W;
    sum = modadd(sum, paths(i, j), MOD);
  }
  cout << sum << endl;
  
  return 0;
}