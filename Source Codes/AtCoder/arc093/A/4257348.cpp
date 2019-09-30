#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

int main() {
  size_t N;
  scanf("%zu", &N);

  std::vector<int> A(N+2);
  for (size_t i = 1; i <= N; ++i)
    scanf("%d", &A[i]);

  int whole = 0;
  for (size_t i = 1; i <= N+1; ++i)
    whole += abs(A[i]-A[i-1]);

  for (size_t i = 1; i <= N; ++i) {
    int cur = whole;
    cur -= abs(A[i]-A[i-1]);
    cur -= abs(A[i+1]-A[i]);
    cur += abs(A[i+1]-A[i-1]);
    printf("%d\n", cur);
  }
}