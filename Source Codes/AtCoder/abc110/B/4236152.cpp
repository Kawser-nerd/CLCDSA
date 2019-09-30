#include <cstdio>
#include <vector>

bool valid(const std::vector<int>& x, const std::vector<int> &y, int Z) {
  for (auto xi: x) if (xi >= Z) return false;
  for (auto yi: y) if (yi < Z) return false;
  return true;
}

int main() {
  size_t N, M;
  int X, Y;
  scanf("%zu %zu %d %d", &N, &M, &X, &Y);

  std::vector<int> x(N), y(M);
  for (auto& xi: x) scanf("%d", &xi);
  for (auto& yi: y) scanf("%d", &yi);

  for (int Z = X+1; Z <= Y; ++Z) 
    if (valid(x, y, Z))
      return puts("No War"), 0;

  puts("War");
}