#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;

int main() {
  ll N, C;
  std::cin >> N >> C;
  std::vector<std::pair<ll, ll>> xv(N);
  std::vector<ll> pnt_right(N);
  std::vector<ll> pnt_left(N);
  for (int i = 0; i < N; ++i) {
    ll x, v;
    std::cin >> x >> v;
    xv[i] = std::make_pair(x, v);
  }
  std::sort(
      xv.begin(), xv.end(),
      [](std::pair<ll, ll> i, std::pair<ll, ll> j) -> bool { return i.first < j.first; }
  );
  long long ans = 0ll;
  long long cur = 0ll;
  long long prev_pos = 0ll;
  for (int i = 0; i < N; ++i) {
    cur += xv[i].second - (xv[i].first - prev_pos);
    prev_pos = xv[i].first;
    ans = std::max(ans, cur);
    pnt_right[i] = ans;
  }
  cur = 0ll;
  prev_pos = C;
  long long ans2 = 0ll;
  for (int i = N - 1; i >= 0; --i) {
    cur += xv[i].second - (prev_pos - xv[i].first);
    prev_pos = xv[i].first;
    ans2 = std::max(ans2, cur);
    pnt_left[i] = ans2;
  }
  ans = std::max(ans, ans2);
  for (int i = 0; i < N - 1; ++i) {
    ans = std::max(ans, pnt_right[i] + pnt_left[i + 1] - xv[i].first);
  }
  for (int i = 0; i < N - 1; ++i) {
    ans = std::max(ans, pnt_right[i] + pnt_left[i + 1] - (C - xv[i + 1].first));
  }

  std::cout << ans << std::endl;

  return 0;
}