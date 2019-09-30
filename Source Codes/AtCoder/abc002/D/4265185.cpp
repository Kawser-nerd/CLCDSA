#include <iostream>
#include <sstream>
#include <set>
using namespace std;
constexpr int MAX_N = 12;
bool xy[MAX_N][MAX_N];

int main() {
  int N, M;
  cin >> N >> M;

  for (int i{}; i < M; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    xy[x][y] = xy[y][x] = true;
  }

  int ans{};
  for (int i{}; i < (1 << N); ++i) {
    set<int> clique;
    for (int j{}; j < N; ++j) {
      if (i & (1 << j)) {
        bool intimate{true};
        for (auto& m : clique) {
          if (!xy[j][m]) {
            intimate = false;
            break;
          }
        }
        if (intimate) {
          clique.insert(j);
        }
      }
    }
    if (ans < clique.size()) {
      ans = clique.size();
    }
  }

  cout << ans << endl;
  return 0;
}