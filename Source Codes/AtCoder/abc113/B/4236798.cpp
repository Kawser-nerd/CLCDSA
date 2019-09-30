#include <cstdio>
#include <cstdlib>

int main() {
  int N;
  scanf("%d", &N);

  int T, A;
  scanf("%d %d", &T, &A);

  int ind = -1;
  int opt = 2e9;
  for (int i = 1; i <= N; ++i) {
    int H;
    scanf("%d", &H);

    if (abs((T*500-H*3)-500*A) < opt) {
      ind = i;
      opt = abs((T*500-H*3)-500*A);
    }
  }
  printf("%d\n", ind);
}