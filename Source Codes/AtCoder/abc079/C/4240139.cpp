#include <cstdio>

int main() {
  int N;
  scanf("%d", &N);

  int A = N / 1000;
  N %= 1000;
  int B = N / 100;
  N %= 100;
  int C = N / 10;
  int D = N % 10;

  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
      for (int k = 0; k < 2; ++k) {
        int lhs = A;
        lhs += (i? B:-B);
        lhs += (j? C:-C);
        lhs += (k? D:-D);
        if (lhs == 7)
          return !printf("%d%c%d%c%d%c%d=7\n",
                         A, "-+"[i], B, "-+"[j], C, "-+"[k], D);
      }
}