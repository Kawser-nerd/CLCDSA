#include <cstdio>
#include <cstdint>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <utility>
#include <tuple>

template <class Tp>
Tp& amax(Tp& dst, const Tp& src) {
  if (dst < src) dst = src;
  return dst;
}

int main() {
  size_t N, K;
  scanf("%zu %zu", &N, &K);

  using sushi = std::pair<intmax_t, intmax_t>;

  std::priority_queue<sushi> q;
  for (size_t i = 0; i < N; ++i) {
    intmax_t t, d;
    scanf("%jd %jd", &t, &d);
    q.emplace(d, t);
  }

  constexpr intmax_t inf = 1e14;
  std::vector<intmax_t> f(N+1, -inf);
  std::priority_queue<sushi> s;
  std::map<intmax_t, intmax_t> count;
  intmax_t cur = 0;
  for (size_t i = 0; i < K; ++i) {
    intmax_t t, d;
    std::tie(d, t) = q.top();
    q.pop();
    ++count[t];
    cur += d;
    s.emplace(-d, t);
  }

  f[count.size()] = cur;

  while (!q.empty()) {
    while (!s.empty()) {
      intmax_t t, d;
      std::tie(d, t) = s.top();
      d = -d;
      s.pop();
      if (count[t] > 1) {
        --count[t];
        cur -= d;
        break;
      }
    }
    if (s.empty()) break;

    while (!q.empty()) {
      intmax_t t, d;
      std::tie(d, t) = q.top();
      q.pop();
      if (count.find(t) != count.end()) continue;
      count[t] = 1;
      cur += d;
      s.emplace(-d, t);
      break;
    }

    amax(f[count.size()], cur);
  }

  intmax_t res = 0;
  for (size_t i = 1; i <= N; ++i)
    res = amax<intmax_t>(res, f[i]+i*i);

  printf("%jd\n", res);
}