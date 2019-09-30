#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
  size_t N;
  scanf("%zu", &N);

  std::vector<int> t(N);
  int tsum = 0;
  for (auto& ti: t) {
    scanf("%d", &ti);
    ti += ti;
    tsum += ti;
  }

  std::vector<int> v(N);
  for (auto& vi: v) {
    scanf("%d", &vi);
    vi += vi;
  }

  std::vector<int> maxv{0};
  for (size_t i = 0; i < N; ++i) {
    if (maxv.back() > v[i]) maxv.back() = v[i];
    for (int j = 0; j < t[i]; ++j)
      maxv.push_back(v[i]);
  }
  maxv[tsum] = 0;

  std::vector<int> res(tsum+1);
  for (int i = 0; i <= tsum; ++i) {
    res[i] = 1e9;
    for (int j = 0; j < i; ++j) res[i] = std::min(res[i], res[j]+i-j);
    for (int j = i; j <= tsum; ++j) res[i] = std::min(res[i], maxv[j]+(j-i));
  }

  printf("%.12f\n", std::accumulate(res.begin(), res.end(), 0)/4.0);
}