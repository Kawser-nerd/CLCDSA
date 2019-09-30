#include <iostream>
using namespace std;

// https://atcoder.jp/contests/abc054/submissions/me

constexpr int MAX_N = 8;

int N, M;
bool graph[MAX_N+1][MAX_N+1];
int idx[]{1, 2, 3, 4, 5, 6, 7, 8};

int main() {
  scanf("%d%d", &N, &M);
  for (int i{}; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    graph[a][b] = graph[b][a] = true;
  }
  int total{};

  do {
    bool reachedAll{true};
    for (int i{}; i < N-1; ++i) {
      if (!graph[idx[i]][idx[i+1]]) {
        reachedAll = false;
        break;
      }
    }
    if (reachedAll)
      ++total;
  } while (next_permutation(idx + 1, idx + N));

  printf("%d\n", total);
  return 0;
}