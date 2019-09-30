#include <iostream>
#include <vector>

int main() {
  unsigned n, m;
  std::cin >> n >> m;
  unsigned long long num = 0;
  unsigned long long cost = 0;
  unsigned long long ans = 0;
  std::vector<std::pair<unsigned, unsigned>> a(n);
  std::vector<std::pair<unsigned, unsigned>> x(n);
  std::vector<std::pair<unsigned, unsigned>> y(n);
  std::cin >> a[0].second;
  for (unsigned i = 1; i < n; ++i) {
    std::cin >> a[i].second;
    a[i].first = a[i - 1].second;
    x[i].first = a[i].first;
    x[i].second = i;
    y[i].first = a[i].second;
    y[i].second = i;
    if (a[i].first > a[i].second) {
      cost += m - a[i].first;
      ++num;
      ans += m - a[i].first + a[i].second;
    } else {
      ans += a[i].second - a[i].first;
    }
  }
  std::sort(x.begin() + 1, x.end(),
            [](std::pair<unsigned, unsigned> i, std::pair<unsigned, unsigned> j) -> bool {
              return i.first < j.first;
            });
  std::sort(y.begin() + 1, y.end(),
            [](std::pair<unsigned, unsigned> i, std::pair<unsigned, unsigned> j) -> bool {
              return i.first < j.first;
            });
  auto px = x.begin() + 1;
  auto py = y.begin() + 1;
  std::vector<unsigned long long> costv(m + 1);
  for (unsigned i = 1; i <= m; ++i) {
    costv[i] = cost;
    cost += num;
    while (py < y.end() && py->first == i) {
      if (a[py->second].first < a[py->second].second) {
        cost -= a[py->second].second - a[py->second].first;
      } else {
        cost -= m + a[py->second].second - a[py->second].first;
      }
      --num;
      ++py;
    }
    while (px < x.end() && px->first == i) {
      ++num;
      ++px;
    }
  }
  auto hoge = ans;
  for (unsigned i = 1; i < m + 1; ++i) {
    hoge = std::min(hoge, ans - costv[i]);
  }
  std::cout << hoge;
  return 0;
}