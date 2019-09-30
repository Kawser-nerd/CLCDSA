#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define MP make_pair
#define all(v) (v).begin(), (v).end()
#define PROBLEM_ID "A"

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef long long ll;
typedef pair<int, int> pii;

bool hasOneColor(const vector<string>& field, int k, char c) {
  for (int row = 0; row < field.size(); ++row) {
    for (int column = 0; column < field[row].length(); ++column) {
      for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
          if (abs(dx) + abs(dy) > 0) {
            bool ok = true;
            for (int t = 0; t < k; ++t) {
              int nrow = row + dx * t;
              int ncol = column + dy * t;
              if (nrow < 0 || nrow >= field.size() || ncol < 0 || ncol >= field[nrow].size()) {
                ok = false;
                break;
              }
              if (field[nrow][ncol] != c) {
                ok = false;
                break;
              }
            }
            if (ok) {
              return true;
            }
          }
        }
      }
    }
  }
  return false;
}

int main() {
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int test_count;
  cin >> test_count;
  for (int test_index = 0; test_index < test_count; ++test_index) {
    int rows, columns;
    int k;
    cin >> rows >> k;
    columns = rows;
    vector<string> field(rows);
    for (int i = 0; i < rows; ++i) {
      cin >> field[i];
    }
    vector<string> new_field(columns, string(rows, '.'));
    for (int new_row = 0; new_row < columns; ++new_row) {
      for (int new_column = 0; new_column < rows; ++new_column) {
        new_field[new_row][new_column] = field[rows - new_column - 1][new_row];
      }
    }
    swap(rows, columns);
    field.swap(new_field);
    for (int column = 0; column < columns; ++column) {
      for (int row = rows - 2; row >= 0; --row) {
        int nrow = row;
        while (nrow + 1 < rows && field[nrow][column] != '.' && field[nrow + 1][column] == '.') {
          swap(field[nrow][column], field[nrow + 1][column]);
          ++nrow;
        }
      }
    }
    bool hasBlue = hasOneColor(field, k, 'B');
    bool hasRed = hasOneColor(field, k, 'R');
    cout << "Case #" << test_index + 1 << ": ";
    if (hasBlue && hasRed) {
      cout << "Both" << endl;
    } else if (hasBlue) {
      cout << "Blue" << endl;
    } else if (hasRed) {
      cout << "Red" << endl;
    } else {
      cout << "Neither" << endl;
    }
  }
  return 0;
}
