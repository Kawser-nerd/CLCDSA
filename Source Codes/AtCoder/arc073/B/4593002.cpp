#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>

int main() {
  size_t N;
  intmax_t W;
  scanf("%zu %jd", &N, &W);

  std::vector<std::vector<intmax_t>> v(4);
  intmax_t w1;
  {
    intmax_t v1;
    scanf("%jd %jd", &w1, &v1);
    v[0].push_back(v1);
  }

  for (size_t i = 1; i < N; ++i) {
    intmax_t wi, vi;
    scanf("%jd %jd", &wi, &vi);
    v[wi-w1].push_back(vi);
  }

  std::vector<std::vector<intmax_t>> vv(4);
  for (size_t i = 0; i < 4; ++i) {
    std::sort(v[i].rbegin(), v[i].rend());
    vv[i].push_back(0);
    for (size_t j = 0; j < v[i].size(); ++j)
      vv[i].push_back(vv[i][j]+v[i][j]);
  }

  intmax_t res = 0;
  for (size_t i = 0; i < vv[0].size(); ++i) {
    for (size_t j = 0; j < vv[1].size(); ++j) {
      for (size_t k = 0; k < vv[2].size(); ++k) {
        for (size_t l = 0; l < vv[3].size(); ++l) {
          intmax_t w = w1*i + (w1+1)*j + (w1+2)*k + (w1+3)*l;
          if (w > W) break;
          res = std::max(res, vv[0][i]+vv[1][j]+vv[2][k]+vv[3][l]);
        }
      }
    }
  }
  printf("%jd\n", res);
}