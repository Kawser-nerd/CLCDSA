#include <cstdio>
#include <cassert>
#include <vector>

int main() {
  size_t N;
  scanf("%zu", &N);

  size_t M = 55555;
  std::vector<bool> prime(M+1, true);
  prime[0] = prime[1] = false;
  for (size_t i = 2; i*i <= M; ++i) {
    if (!prime[i]) continue;
    for (size_t j = i*i; j <= M; j += i) 
      prime[j] = false;
  }

  std::vector<int> res;
  for (size_t i = 1; i <= M; i += 5)
    if (prime[i])
      res.push_back(i);

  for (size_t i = 0; i < N; ++i)
    printf("%d\n", res[i]);
}