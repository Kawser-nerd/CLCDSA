#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <numeric>
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

i32 N, Q;

vector<i32> X, R, H, A, B;

void input() {
#ifdef DEBUG
  ifstream in(XSTR(INPUT));
#else
  istream &in = cin;
#endif
  in >> N >> Q;
  X.resize(N);
  R.resize(N);
  H.resize(N);
  for (i32 i = 0; i < N; i++) {
    in >> X[i] >> R[i] >> H[i];
  }
  A.resize(Q);
  B.resize(Q);
  for (i32 i = 0; i < Q; i++) {
    in >> A[i] >> B[i];
  }
}

double vol(i32 i, i32 a, i32 b) {
  double p = X[i] + H[i];
  double x_max = min(X[i] + H[i], b);
  double x_min = max(X[i], a);
  double r = R[i];
  double r1 = r * (p - x_min) / H[i];
  double r2 = r * (p - x_max) / H[i];
  return M_PI / 3.0 * (r1 * r1 * (p - x_min) - r2 * r2 * (p - x_max));
}

bool compare(i32 i, i32 j) {
  if (X[i] + H[i] < X[j] + H[j]) {
    return true;
  }
  else if (X[i] + H[i] > X[j] + H[j]) {
    return false;
  }
  return X[i] < X[j];
}

bool joint(i32 i, i32 a, i32 b) {
  if (X[i] >= b || X[i] + H[i] <= a) {
    return false;
  }
  return true;
}

int main() {
  input();

  vector<double> vs;
  vs.resize(2 * 10000);
  for (i32 i = 0; i < vs.size(); i++) {
    double v = 0;
    for (i32 j = 0; j < N; j++) {
      if (joint(j, 0, i)) {
        v += vol(j, 0, i);
      }
    }
    vs[i] = v;
  }
  
  for (i32 i = 0; i < Q; i++) {
    printf("%.4lf\n", vs[B[i]] - vs[A[i]]);
  }
  
  return 0;
}