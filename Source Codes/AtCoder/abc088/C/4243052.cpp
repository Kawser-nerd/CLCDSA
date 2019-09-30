#include <cstdio>
#include <vector>

int main() {
  std::vector<std::vector<int>> c(3, std::vector<int>(3));
  auto d = c;
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) {
      scanf("%d", &c[i][j]);
      d[j][i] = c[i][j];
    }

  for (int i = 0; i < 3; ++i) {
    for (int j: std::vector<int>{1, 2, 0}) {
      c[i][j] -= c[i][0];
      d[i][j] -= d[i][0];
    }
  }

  bool valid = true;
  {
    if (c[0] != c[1] || c[0] != c[2]) valid = false;
    if (d[0] != d[1] || d[0] != d[2]) valid = false;
  }
  puts(valid? "Yes":"No");
}