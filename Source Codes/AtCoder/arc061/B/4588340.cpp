#include <cstdio>
#include <cstdint>
#include <vector>
#include <map>
#include <algorithm>
#include <tuple>

constexpr size_t dd[] = {size_t(-1), 0, 1};

int main() {
  size_t H, W, N;
  scanf("%zu %zu %zu", &H, &W, &N);

  std::map<std::pair<size_t, size_t>, int> g;
  for (size_t i = 0; i < N; ++i) {
    size_t a, b;
    scanf("%zu %zu", &a, &b);
    --a;
    --b;

    for (size_t da: dd)
      for (size_t db: dd) {
        size_t na = a + da;
        size_t nb = b + db;
        if (!(na < H && nb < W)) continue;
        ++g[{na, nb}];
      }
  }

  std::vector<uintmax_t> res(10);
  res[0] = (H-2)*(W-2);
  for (const auto& p: g) {
    size_t a, b;
    std::tie(a, b) = p.first;
    if (a == 0 || a+1 == H || b == 0 || b+1 == W) continue;
    ++res[p.second];
    --res[0];
  }

  for (auto ri: res) printf("%ju\n", ri);
}