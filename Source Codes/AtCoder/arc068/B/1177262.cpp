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
#define MAX_N (100000)
#define MAX_A (100000)
int N, M, K, COUNTS[MAX_A];

int main() {
  M = K = 0;
  for (int i = 0; i < N; i++) COUNTS[i] = 0;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int a;
    scanf("%d", &a);
    if (COUNTS[a] == 0) M++;
    if (COUNTS[a] > 0) K++;
    COUNTS[a]++;
  }
  debug_printf("%d %d\n", M, K);

  int ans = (K % 2 == 0)? M: M - 1;
  printf("%d\n", ans);

  return 0;
}