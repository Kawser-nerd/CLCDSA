#include <iostream>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  int vertex[N];
  for (int i{}; i < N; ++i)
    vertex[i] = i+1;
  bool edge[N+1][N+1];
  fill(edge[0], edge[0]+(N+1)*(N+1), false);
  for (int i{}; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    edge[a][b] = edge[b][a] = true;
  }

  int ans{};
  sort(vertex, vertex + N); // ??????????????
  do {
    bool path{true};
    for (int i{}; i < N-1; ++i) {
      if (!edge[vertex[i]][vertex[i+1]]) {
        path = false;
        break;
      }
    }
    if (path)
      ++ans;
  } while (next_permutation(vertex + 1, vertex + N));

  cout << ans << endl;
  return 0;
}