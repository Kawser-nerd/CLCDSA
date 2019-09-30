#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <cstdlib>
#include <utility>

using namespace std;

#define MAXN 10010

int mq_a, mq_b, mq_va, mq_vb;
int mq_v[MAXN];
int mq_i[MAXN];

void mq_init() {
  mq_a = mq_b = mq_va = mq_vb = 0;
}

void mq_push(int v) {
  while(mq_va < mq_vb && mq_v[mq_vb - 1] <= v) mq_vb--;
  mq_v[mq_vb] = v;
  mq_i[mq_vb++] = mq_b++;
}

void mq_pop() {
  mq_va += mq_a++ == mq_i[mq_va];
}

int mq_max() {
  return mq_v[mq_va];
}

int A[MAXN];

int main() {
  int T; cin >> T;
  for(int t = 1; t <= T; t++) {
    int E, R, N;
    cin >> E >> R >> N;

    A[0] = E;
    long long res = 0;
    if(E < R) for(int i = 0; i < N; i++) {
      int v; cin >> v;
      res += 1ll * v * E;
    } else for(int i = 1, j = 0; i <= N; i++) {
      int v; cin >> v;
      mq_push(v);

      int x = i == N ? E : R;
      for(; x; ) {
        int amt = min(A[j], x);
        res += 1ll * mq_max() * amt;
        x -= amt;
        A[j] -= amt;
        if(A[j] == 0) {
          mq_pop();
          j++;
        }
      }
      A[i] = R;
    }
    cout << "Case #" << t << ": " << res << endl;
  }
  return 0;
}
