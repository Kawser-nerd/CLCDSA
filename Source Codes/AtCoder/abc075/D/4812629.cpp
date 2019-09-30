#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

struct Pos {
  int64_t x, y;
  Pos(int a, int b) {
    x = a;
    y = b;
  }
};

int main(void) {
  cout << std::fixed << std::setprecision(10);
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  int n, limit;
  cin >> n >> limit;
  std::vector<Pos> point;
  int64_t result = 4000000000000000001LL;
  // cerr << "\033[93m" << result << "\033[m" << endl;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    point.push_back(Pos(x, y));
  }
  for (int h = 0; h < n; h++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          Pos point_a(point[h].x, point[i].y);
          Pos point_b(point[j].x, point[k].y);
          // printf("(%d,%d) (%d,%d)", point_a.x, point_a.y, point_b.x,
          // point_b.y);
          int64_t count = 0;
          int64_t x_min = std::min(point_a.x, point_b.x);
          int64_t x_max = std::max(point_a.x, point_b.x);
          int64_t y_min = std::min(point_a.y, point_b.y);
          int64_t y_max = std::max(point_a.y, point_b.y);
          for (auto target : point) {
            if (x_min <= target.x && target.x <= x_max && y_min <= target.y &&
                target.y <= y_max) {
              count++;
            }
          }
          // cerr << "\033[93m"
          //  << "count: " << k << " " << count << "\033[m" << endl;
          // cerr << "\033[93m" << result << "\033[m" << endl;
          if (limit <= count) {
            // cerr << "k<=count" << endl;
            int64_t area = 0;
            if (y_max == y_min) {
              area = (x_max - x_min);
            } else if (x_max == x_min) {
              area = (y_max - y_min);
            } else {
              area = (y_max - y_min) * (x_max - x_min);
            }
            result = std::min(result, area);
            // cerr << "\033[93m" << result << "\033[m" << endl;
          }
          // cerr << "\033[93m"
          //  << "result: " << result << "\033[m" << endl;
        }
      }
    }
  }

  cout << result << endl;

  return 0;
}