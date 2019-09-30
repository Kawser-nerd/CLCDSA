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
#define PROBLEM_ID "C"

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef long long ll;
typedef pair<int, int> pii;

int OpValue(int value, int new_value, char op) {
  if (op == '+') {
    return value + new_value;
  } else {
    return value - new_value;
  }
}

const int MAX_QUERY = 251;
const int MAX_VALUES = 4 * MAX_QUERY + 1;
const int ADD = 2 * MAX_QUERY;

int GetElem(int value) {
  return value + ADD;
}

struct State {
  int length;
  string answer;
  int value;
  pii position;

  State(int length_, string answer_, int value_, pii position_): length(length_), answer(answer_), value(value_), position(position_) {}
};

bool operator<(const State& a, const State& b) {
  if (a.length != b.length) {
    return a.length < b.length;
  }
  if (a.answer != b.answer) {
    return a.answer < b.answer;
  }
  if (a.value != b.value) {
    return a.value < b.value;
  }
  return a.position < b.position;
}

int main() {
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int tests;
  cin >> tests;
  for (int test_number = 0; test_number < tests; ++test_number) {
    int width;
    cin >> width;
    int queries;
    cin >> queries;
    vector<string> field(width);
    for (int i = 0; i < width; ++i) {
      cin >> field[i];
    }
    vector<int> all_queries(queries);
    vector<string> answers(queries, "");
    vector<bool> has_query(MAX_QUERY, false);
    for (int i = 0; i < queries; ++i) {
      int query;
      cin >> query;
      all_queries[i] = query;
      has_query[query] = true;
    }
    int diff_queries = 0;
    for (int i = 0; i < MAX_QUERY; ++i) {
      if (has_query[i]) {
        diff_queries++;
      }
    }
    vector< vector< vector<int> > > length(width, vector< vector<int> >(width, vector<int>(MAX_VALUES, -1)));
    vector< vector< vector<string> > > answer(width, vector< vector<string> >(width, vector<string>(MAX_VALUES, "")));
    vector< vector< vector<bool> > > can(width, vector< vector<bool> >(width, vector<bool>(MAX_VALUES, false)));
    set<State> q;
    vector<bool> solved(MAX_VALUES, false);
    for (int row = 0; row < width; ++row) {
      for (int col = 0; col < width; ++col) {
        if (isdigit(field[row][col])) {
          int value = field[row][col] - '0';
          length[row][col][GetElem(value)] = 1;
          answer[row][col][GetElem(value)] += field[row][col];
          solved[GetElem(value)] = true;
          can[row][col][GetElem(value)] = true;
          q.insert(State(1, answer[row][col][GetElem(value)], value, MP(row, col)));          
        }
      }
    }
    int solved_count = 0;
    while (!q.empty()) {
      State cur_position = *q.begin();
      q.erase(q.begin());
      for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
          if (abs(dx) + abs(dy) == 1) {
            int oprow = cur_position.position.first + dx;
            int opcol = cur_position.position.second + dy;
            if (oprow >= 0 && oprow < width && opcol >= 0 && opcol < width) {
              char op = field[oprow][opcol];
              for (int ndx = -1; ndx <= 1; ++ndx) {
                for (int ndy = -1; ndy <= 1; ++ndy) {
                  if (abs(ndx) + abs(ndy) == 1) {
                    int nvrow = oprow + ndx;
                    int nvcol = opcol + ndy;
                    if (nvrow >= 0 && nvrow < width && nvcol >= 0 && nvcol < width) {
                      int new_value = field[nvrow][nvcol] - '0';
                      int value = OpValue(cur_position.value, new_value, op);
                      if (GetElem(value) < 0 || GetElem(value) >= MAX_VALUES) {
                        continue;
                      }
                      string new_answer = cur_position.answer;
                      new_answer += op;
                      new_answer += field[nvrow][nvcol];
                      if (!can[nvrow][nvcol][GetElem(value)] || 
                          length[nvrow][nvcol][GetElem(value)] > cur_position.length + 2 ||
                          (length[nvrow][nvcol][GetElem(value)] == cur_position.length + 2 &&
                          answer[nvrow][nvcol][GetElem(value)] > new_answer)) {
                        can[nvrow][nvcol][GetElem(value)] = true;
                        length[nvrow][nvcol][GetElem(value)] = cur_position.length + 2;
                        answer[nvrow][nvcol][GetElem(value)] = new_answer;
                        q.insert(State(length[nvrow][nvcol][GetElem(value)],
                                     answer[nvrow][nvcol][GetElem(value)],
                                     value,
                                     MP(nvrow, nvcol)));
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    cout << "Case #" << test_number + 1 << ":" << endl;
    for (int query_index = 0; query_index < queries; ++query_index) {
      int query = all_queries[query_index];
      bool found = false;
      int min_length = -1;
      string best_ans;
      for (int row = 0; row < width; ++row) {
        for (int col = 0; col < width; ++col) {
          if (can[row][col][GetElem(query)] && 
              (min_length == -1 || length[row][col][GetElem(query)] < min_length ||
               length[row][col][GetElem(query)] == min_length &&
               answer[row][col][GetElem(query)] < best_ans)) {
            min_length = length[row][col][GetElem(query)];
            best_ans = answer[row][col][GetElem(query)];
          } 
        }
      }
      cout << best_ans << endl;
    }
    cerr << "Test " << test_number + 1 << " of " << tests << " done" << endl;
  }
  return 0;
}
