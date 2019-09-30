#include <cstdio>
#include <cstdint>
#include <cassert>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <set>

std::set<int> reachable(const std::vector<int>& xs) {
  std::set<int> res{0};
  for (int x: xs) {
    std::set<int> tmp;
    for (auto ri: res) {
      tmp.insert(ri-x);
      tmp.insert(ri+x);
    }
    res.swap(tmp);
  }
  return res;
}

int main() {
  char buf[8192];
  scanf("%s", buf);
  std::string s = buf;
  s += "TT";

  int x, y;
  scanf("%d %d", &x, &y);

  size_t i = 0;
  while (s[i] == 'F') {
    ++i;
    --x;
  }

  std::vector<int> xs, ys;
  bool xp = false;
  while (i < s.length()) {
    assert(s[i] == 'T');
    ++i;

    int tmp = 0;
    while (s[i] == 'F') {
      ++i;
      ++tmp;
    }

    (xp? xs:ys).push_back(tmp);
    xp = !xp;
  }

  puts((reachable(xs).count(x) && reachable(ys).count(y))? "Yes":"No");
}