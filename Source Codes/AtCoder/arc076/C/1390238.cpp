#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector< pair<int, int> > points;

int length(const int x, const int y, const int R, const int C) {
  if (y == 0) {
    return x;
  }
  else if (x == R) {
    return R+y;
  }
  else if (y == C) {
    return 2*R+C-x;
  }
  else {
    return 2*R+2*C-y;
  }
}

void solve() {
  sort(points.begin(), points.end());
  vector<int> stack;
  for (pair<int, int> point : points) {
    if (stack.size() == 0 || stack.back() != point.second) {
      stack.push_back(point.second);
    }
    else {
      stack.pop_back();
    }
    //cout << "stack: ";
    // for (int x : stack) {
    //   cout << x << " ";
    // }
    // cout << endl;
  }
  if (stack.size() == 0) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}

int main() {
  int N, R, C;
  cin >> R >> C >> N;
  int x1, y1, x2, y2;
  for (int i = 0; i < N; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    if ((x1 == 0 || y1 == 0 || x1 == R || y1 == C) &&
	(x2 == 0 || y2 == 0 || x2 == R || y2 == C)) {
      pair<int, int> p1, p2;
      p1 = make_pair(length(x1, y1, R, C), i);
      p2 = make_pair(length(x2, y2, R, C), i);
      points.push_back(p1);
      points.push_back(p2);
      // cout << "point " << i << ": " << p1.first << endl;
      // cout << "point " << i << ": " << p2.first << endl;
    }
  }
  solve();
}