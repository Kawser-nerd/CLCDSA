#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;


class Solver {
  public:
    int h, w;
    string s[100];
    string original[100];
    bool can_exist() {
      for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
          int b = 0;
          int a = 0;
          for (int dy = -1; dy <= 1; ++dy) {
            for (int dx = -1; dx <= 1; ++dx) {
              int nx = x + dx;
              int ny = y + dy;
              if (0 <= nx and nx < w and 0 <= ny and ny < h) {
                ++a;
                if (s[ny][nx] == '#') {
                  ++b;
                }
              }
            }
          }
          original[y].push_back(a == b? '#': '.');
        }
      }
      for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
          int b = 0;
          for (int dy = -1; dy <= 1; ++dy) {
            for (int dx = -1; dx <= 1; ++dx) {
              int nx = x + dx;
              int ny = y + dy;
              if (0 <= nx and nx < w and 0 <= ny and ny < h and original[ny][nx] == '#') {
                ++b;
              }
            }
          }
          if ((b == 0) != (s[y][x] == '.')) {
            return false;
          }
        }
      }
      return true;
    }
};

int main() {
  Solver s;
  cin >> s.h >> s.w;
  for (int y = 0; y < s.h; ++y) {
    cin >> s.s[y];
  }
  if (s.can_exist()) {
    cout << "possible" << endl;
    for (int y = 0; y < s.h; ++y) {
      cout << s.original[y] << endl;
    }
  } else {
    cout << "impossible" << endl;
  }
  return 0;
}