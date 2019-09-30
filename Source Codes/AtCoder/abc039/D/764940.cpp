#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

typedef std::vector<std::string> G;

int main()
{
  int h, w;
  std::cin >> h >> w;

  G s(h);
  for (int i = 0; i < h; i++) {
    std::cin >> s[i];
  }

  G t(h, std::string(w, '#'));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      int cnt = 0;
      for (int di = -1; di <= 1; ++di) {
        for (int dj = -1; dj <= 1; ++dj) {
          int ni = i + di, nj = j + dj;
          if (ni < 0 || nj < 0 || ni >= h || nj >= w || s[ni][nj] == '#') {
            cnt++;
          }
        }
      }
      if (cnt == 9) {
        t[i][j] = '#';
      } else {
        t[i][j] = '.';
      }
    }
  }

  G u = t;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {

      if (t[i][j] == '.') {
        continue;
      }

      for (int di = -1; di <= 1; ++di) {
        for (int dj = -1; dj <= 1; ++dj) {
          int ni = i + di, nj = j + dj;
          if (ni < 0 || nj < 0 || ni >= h || nj >= w) {
            continue;
          }
          u[ni][nj] = '#';
        }
      }
    }
  }

  bool is_possible = true;
  for (int i = 0; i < h; ++i) {
    if (s[i] != u[i]) {
      is_possible = false;
      break;
    }
  }

  if (is_possible) {
    std::cout << "possible" << std::endl;
    for (std::string s : t) {
      std::cout << s << std::endl;
    }
  } else {
    std::cout << "impossible" << std::endl;
  }
}