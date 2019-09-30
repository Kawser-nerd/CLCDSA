#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> Vi;
typedef vector<Vi> Mi;
typedef vector<string> Vs;

Vi min_col;
Vi max_col;
Vi min_row;
Vi max_row;

bool can_change(int i, int j) {
  return min_col[j] < i or max_row[i] > j or max_col[j] > i or min_row[i] < j;
}

int main() {
  int tcas;
  cin >> tcas;
  for (int cas = 1; cas <= tcas; ++cas) {
    int R, C;
    cin >> R >> C;
    Vs mat(R);
    for (int i = 0; i < R; ++i) {
      cin >> mat[i];
    }
    min_col = Vi(C, R);
    max_col = Vi(C, -1);
    min_row = Vi(R, C);
    max_row = Vi(R, -1);
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        if (mat[i][j] != '.') {
          min_col[j] = min(min_col[j], i);
          max_col[j] = max(max_col[j], i);
          min_row[i] = min(min_row[i], j);
          max_row[i] = max(max_row[i], j);
        }
      }
    }
    bool impossible = false;
    int changes = 0;
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        bool need_change =
          (mat[i][j] == '^' and min_col[j] == i) or
          (mat[i][j] == '>' and max_row[i] == j) or
          (mat[i][j] == 'v' and max_col[j] == i) or
          (mat[i][j] == '<' and min_row[i] == j);
        if (need_change) {
          ++changes;
          if (not can_change(i, j)) {
            impossible = true;
          }
        }
      }
    }
    cout << "Case #" << cas << ": ";
    if (impossible) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      cout << changes << endl;
    }
  }
}
