#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
#include <functional>

template <class ForwardIt, class Compare>
auto f(ForwardIt first, ForwardIt mid1, ForwardIt mid2, ForwardIt last, Compare comp) {
  using Tp = typename ForwardIt::value_type;

  std::vector<Tp> res;
  Tp sum = 0;
  std::priority_queue<Tp, std::vector<Tp>, Compare> q(comp);
  for (auto it = first; it != mid1; ++it) {
    sum += *it;
    q.push(*it);
  }

  res.push_back(sum);
  for (auto it = mid1; it != mid2; ++it) {
    sum += *it;
    q.push(*it);
    sum -= q.top();
    q.pop();
    res.push_back(sum);
  }

  return res;
}

int main() {
  size_t N;
  scanf("%zu", &N);

  std::vector<intmax_t> a(3*N);
  for (auto& ai: a) scanf("%jd", &ai);

  auto sa = f(a.begin(), a.begin()+N, a.end()-N, a.end(), std::greater<intmax_t>());
  auto sb = f(a.rbegin(), a.rbegin()+N, a.rend()-N, a.rend(), std::less<intmax_t>());

  // for (size_t i = 0; i < sa.size(); ++i)
  //   fprintf(stderr, "%jd%c", sa[i], i+1<sa.size()? ' ':'\n');

  // for (size_t i = 0; i < sb.size(); ++i)
  //   fprintf(stderr, "%jd%c", sb[i], i+1<sb.size()? ' ':'\n');

  intmax_t res = -1e14;
  for (size_t i = 0; i <= N; ++i)
    res = std::max(res, sa[i]-sb[N-i]);

  printf("%jd\n", res);
}