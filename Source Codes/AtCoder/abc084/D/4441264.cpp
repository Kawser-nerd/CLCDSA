#include <cstdio>
#include <vector>

int main() {
  int M = 100000;
  std::vector<int> prime(M+1, 1);
  prime[0] = prime[1] = 0;
  for (int i = 2; i*i <= M; ++i)
    if (prime[i])
      for (int j = i*i; j <= M; j += i)
        prime[j] = 0;

  std::vector<int> res(M+1);
  for (int i = 1; i <= M; ++i)
    if (prime[i] && prime[(i+1)/2])
      res[i] = 1;

  for (int i = 1; i <= M; ++i)
    res[i] += res[i-1];

  int Q;
  scanf("%d", &Q);

  for (int i = 0; i < Q; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    printf("%d\n", res[r]-res[l-1]);
  }
}