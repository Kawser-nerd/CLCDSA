#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, C;
  cin >> N >> C;

  vector<vector<int>> D(C, vector<int>(C, 0));
  for (int i = 0; i < C; i++) {
    for (int j = 0; j < C; j++) {
      cin >> D[i][j];
    }
  }

  vector<vector<int>> CC(N, vector<int>(N, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> CC[i][j];
      CC[i][j]--; // ?????????
    }
  }

  vector<vector<int>> cost(3, vector<int>(C, 0));
  for (int c = 0; c < C; c++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cost[(i + j) % 3][c] += D[CC[i][j]][c];
      }
    }
  }

  int res = INT_MAX;
  int c[3];
  for (c[0] = 0; c[0] < C; c[0]++) {
    for (c[1] = 0; c[1] < C; c[1]++) {
      if (c[1] == c[0])
        continue;

      for (c[2] = 0; c[2] < C; c[2]++) {
        if (c[2] == c[0] || c[2] == c[1])
          continue;

        int tmp = 0;
        for (int it = 0; it < 3; it++)
          tmp += cost[it][c[it]];

        res = min(res, tmp);
      }
    }
  }
  cout << res << endl;
  return 0;
}