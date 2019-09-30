#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

//#define DEBUG
#ifdef DEBUG
#define debug_printf printf
#else
#define debug_printf 1 ? 0 : printf
#endif

using namespace std;
typedef long long int ll;
typedef vector<ll> Vl;
typedef vector<int> Vi;
typedef pair<int, int> Pi;

#define INF   (1e9 + 7)
#define MAX_N (5000)
#define MAX_K (5000)

int N, K;
int A[MAX_N];
bool DP[MAX_K];

void solve() {
  sort(A, A + N);
  ll sum = 0;
  for (int i = 0; i < N; i++) sum += A[i];
  for (int j = 0; j < K; j++) DP[j] = false;
  DP[0] = true;

  int ans = 0;
  for (int i = N - 1; i >= 0; i--) {
    bool no_need = true;
    for (int j = 0; j < K; j++) {
      if (DP[j] && j + sum >= K) {
        no_need = false;
        break;
      }
    }
    if (no_need) ans++;
    debug_printf("sum = %lld, a = %d\n", sum, A[i]);
    for (int j = 0; j < K; j++) debug_printf("%s ", DP[j]? "o": "x");
    debug_printf("\n");

    for (int j = K - A[i] - 1; j >= 0; j--) DP[j + A[i]] |= DP[j];

    sum -= A[i];
  }
  printf("%d\n", ans);
}

int main() {
  scanf("%d %d", &N, &K);
  for (int i = 0; i < N; i++) scanf("%d", &A[i]);

  solve();

  return 0;
}