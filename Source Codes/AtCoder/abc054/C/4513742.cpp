#include <iostream>
using namespace std;

constexpr int MAX_N = 8;
int ab[MAX_N+1][MAX_N+1];
int idx[]{1,2,3,4,5,6,7,8};

int main() {
  int N, M;
  cin >> N >> M;
  for (int i{}; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    ab[a][b] = ab[b][a] = true;
  }
  int ans{};
  sort(idx, idx + N); // ??????????????
  do {
    bool path{true};
    for (int i{1}; i < N; ++i) {
      if (!ab[idx[i-1]][idx[i]]) {
        path = false;
        break;
      }
    }
    if (path)
      ++ans;
  } while (next_permutation(idx+1, idx + N));

  cout << ans << endl;
  return 0;
}