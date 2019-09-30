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

const int diri[4] = {-1, 0, 1, 0};
const int dirj[4] = {0, 1, 0, -1};

int R, C;
Mi mat;
set<Mi> solutions;

bool check(int i, int j) {
  bool strict = true;
  int same = 0;
  for (int k = 0; k < 4; ++k) {
    int ii = i + diri[k];
    int jj = (j + dirj[k] + C)%C;
    if (0 <= ii and ii < R) {
      if (mat[ii][jj] == 0) {
        strict = false;
      } else if (mat[ii][jj] == mat[i][j]) {
        ++same;
      }
    }
  }
  if (strict) {
    return same == mat[i][j];
  }
  return same <= mat[i][j];
}

Mi normalize(Mi m) {
  Mi res = m;
  for (int k = 0; k < C; ++k) {
    Mi m2(R, Vi(C));
    for (int i = 0; i < R; ++i)
      for (int j = 0; j < C; ++j)
        m2[i][j] = m[i][(j + k)%C];
    if (m2 < res) res = m2;
  }
  return res;
}

void bt(int i, int j) {
  if (i == R) {
    solutions.insert(normalize(mat));
    return;
  }
  if (j == C) {
    return bt(i + 1, 0);
  }
  for (int k = 1; k <= 3; ++k) {
    mat[i][j] = k;
    if (check(i, j) and
        (i == 0 || check(i - 1, j)) and
        (j == 0 || check(i, j - 1)) and
        (j != C - 1 || check(i, 0))) {
      bt(i, j + 1);
    }
    mat[i][j] = 0;
  }
}

int compute(int rows, int cols) {
  R = rows;
  C = cols;
  mat = Mi(R, Vi(C, 0));
  solutions.clear();
  bt(0, 0);
  return solutions.size();
}

int main() {
  int tcas;
  cin >> tcas;
  for (int cas = 1; cas <= tcas; ++cas) {
    int r, c;
    cin >> r >> c;
    int res = compute(r, c);
    cout << "Case #" << cas << ": " << res << endl;
  }
}
