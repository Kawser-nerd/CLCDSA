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
#define PROBLEM_ID "D"

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef long long ll;
typedef pair<int, int> pii;

pii Move(const vector<string>& field, int row, int col, int dir, bool reverse) {
  pii result = MP(row, col);
  if (dir == 0) {
    ++col;
  } else if (dir == 1) {
    --col;
  } else if (dir == 2) {
    if (reverse) {
      --row;
    } else {
      ++row;
    }
  } else {
    cerr << "Wrong dir: " << dir << endl;
    abort();
  }
  if (col < 0 || row < 0 || col >= field[0].size() || row >= field.size() || field[row][col] == '#') {
    return result;
  } else {
    return MP(row, col);
  }
}

pair<int, bool> Solve(const vector<string>& field, int row, int col) {
  queue<pii> q;
  vector<vector<bool> > done(field.size(), vector<bool>(field[0].size()));
  vector<pii> all;
  q.push(MP(row, col));
  done[row][col] = true;
  all.push_back(MP(row, col));
  while (!q.empty()) {
    pii cur = q.front();
    q.pop();
    for (int dir = 0; dir < 3; ++dir) {
      pii next = Move(field, cur.first, cur.second, dir, true);
      if (!done[next.first][next.second]) {
        done[next.first][next.second] = true;
        q.push(next);
        all.push_back(next);
      }
    }
  }
  pair<int, bool> result;
  result.first = all.size();
  result.second = false;
  queue<set<pii> > reachable_sets;
  reachable_sets.push(set<pii>(all.begin(), all.end()));
  set< set<pii> > was;
  was.insert(reachable_sets.front());
  while (!reachable_sets.empty()) {
    set<pii> cur_set = reachable_sets.front();
    reachable_sets.pop();
    if (cur_set.size() == 1) {
      pii only = *cur_set.begin();
      if (only.first == row && only.second == col) {
        result.second = true;
        break;
      }
    }
    if (was.size() % 1000 == 0) {
      cerr << "was.size() = " << was.size() << endl;
    }
    for (int dir = 0; dir < 3; ++dir) {
      set<pii> next_set;
      for (set<pii>::const_iterator it = cur_set.begin(); it != cur_set.end(); ++it) {
        pii from = *it;
        pii to = Move(field, from.first, from.second, dir, false);
        next_set.insert(to);
      }
      if (!was.count(next_set)) {
        was.insert(next_set);
        reachable_sets.push(next_set);
        if (next_set.size() == 1) {
          pii only = *next_set.begin();
          if (only.first == row && only.second == col) {
            result.second = true;
            break;
          }
        }
      }
    }
    if (result.second) {
      break;
    }
  }
  return result;
}

int main() {
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int test_count;
  cin >> test_count;
  for (int test_index = 0; test_index < test_count; ++test_index) {
    int rows, cols;
    cin >> rows >> cols;
    vector<string> field(rows);
    for (int i = 0; i < rows; ++i) {
      cin >> field[i];
    }
    cout << "Case #" << test_index + 1 << ":" << endl;
    cerr << "Case #" << test_index + 1 << ":" << endl;
    for (int i = 0; i <= 9; ++i) {
      for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
          if (field[row][col] == '0' + i) {
            pair<int, bool> result = Solve(field, row, col);
            cout << i << ": " << result.first << " ";
            if (result.second) {
              cout << "Lucky";
            } else {
              cout << "Unlucky";
            }
            cout << endl;
          }
        }
      }
    }
  }
  return 0;
}
