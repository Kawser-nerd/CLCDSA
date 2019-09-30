#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

bool valid(const std::vector<int>& x, const std::vector<int>& y,
           const std::vector<int>& h, int Cx, int Cy, int &H) {

  size_t N = x.size();
  {
    int dx = abs(Cx-x[0]);
    int dy = abs(Cy-y[0]);
    H = h[0]+dx+dy;
  }
  for (size_t i = 1; i < N; ++i) {
    int dx = abs(Cx-x[i]);
    int dy = abs(Cy-y[i]);
    if (h[i] == 0) {
      if (H-(dx+dy) > 0) return false;
      continue;
    }
    if (H != h[i]+dx+dy) return false;
  }
  return true;
}

int main() {
  size_t N;
  scanf("%zu", &N);

  std::vector<int> x(N), y(N), h(N);
  for (size_t i = 0; i < N; ++i)
    scanf("%d %d %d", &x[i], &y[i], &h[i]);

  for (size_t i = 0; i < N; ++i)
    if (h[i] > 0) {
      std::swap(x[i], x[0]);
      std::swap(y[i], y[0]);
      std::swap(h[i], h[0]);
      break;
    }

  int Cx, Cy, H;
  for (Cx = 0; Cx <= 100; ++Cx)
    for (Cy = 0; Cy <= 100; ++Cy)
      if (valid(x, y, h, Cx, Cy, H))
        return !printf("%d %d %d\n", Cx, Cy, H);

  return 1;
}