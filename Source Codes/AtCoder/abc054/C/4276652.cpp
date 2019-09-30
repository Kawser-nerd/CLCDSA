#include <iostream>
using namespace std;

constexpr int MAX_N = 8;

bool r[MAX_N + 1][MAX_N + 1];

int main() {
  int N, M;
  cin >> N >> M;
  for (int i{}; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    r[a][b] = r[b][a] = true;
  }
  int index[MAX_N];
  for (int i{}; i < N; ++i) {
    index[i] = i + 1;
  }

//  sort(index, index + N); // ??????????????
  int count{};
  do {
    bool ok{true};
    for (int i{}; i < N - 1; ++i) {
      if (!r[index[i]][index[i + 1]]) {
        ok = false;
        break;
      }
    }
    if (ok)
      ++count;
  } while (next_permutation(index + 1, index + N));

  cout << count << endl;
  return 0;
}