#include <iostream>
using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

#define DIVUP(x, y) (((x) + ((y) - 1)) / (y))
#define DIVOFF(x, y) (((x) + ((y) / 2)) / (y))
#define REMAINDER(x, y) ((x) % (y))

#define MAX_N 100
#define MAX_M (MAX_N*(MAX_N-1)/2)
int UV[MAX_N+1][MAX_N+1];
bool used[MAX_N+1]; // 0?????
int N, M;

bool dfs(int prev, int cur) {
  if (used[cur]) return true;
  used[cur] = true;
  bool result = false;
  for (int i{1}; i <= N; ++i) {
    if (i == prev) continue;
    if (UV[cur][i]) {
      result |= dfs(cur, i);
    }
  }
  return result;
}

int main() {
  scanf("%d%d", &N, &M);
  int u, v;
  for (int i{}; i < M; ++i) {
    scanf("%d%d", &u, &v);
    UV[u][v] = true;
    UV[v][u] = true;
  }

  int count{};
  for (int i{1}; i <= N; ++i) {
    if (used[i]) continue;
    if (!dfs(0, i)) ++count;
  }

  printf("%d\n", count);
  return 0;
}