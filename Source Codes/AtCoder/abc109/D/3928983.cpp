#include <iostream>
#include <vector>
using namespace std;
using pint  = pair<int, int>;
using ppint = pair<pint, pint>;

int main() {
  int H, W;
  cin >> H >> W;

  vector<vector<int>> A(H, vector<int>(W, 0));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A[i][j];
    }
  }

  vector<ppint> ans;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W - 1; j++) {
      if (A[i][j] % 2 == 0)
        continue;
      A[i][j]--;
      A[i][j + 1]++;
      ans.push_back(ppint(pint(i, j), pint(i, j + 1)));
    }
  }
  for (int i = 0; i < H - 1; i++) {
    if (A[i][W - 1] % 2 == 0)
      continue;
    A[i][W - 1]--;
    A[i + 1][W - 1]++;
    ans.push_back(ppint(pint(i, W - 1), pint(i + 1, W - 1)));
  }

  cout << ans.size() << endl;
  for (auto p : ans) {
    cout << p.first.first + 1 << " " << p.first.second + 1 << " ";
    cout << p.second.first + 1 << " " << p.second.second + 1 << endl;
  }
  return 0;
}