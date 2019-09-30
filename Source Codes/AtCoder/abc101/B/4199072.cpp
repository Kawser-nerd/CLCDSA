#include <cstdio>

int main() {
  int N;
  scanf("%d", &N);

  int Sn = 0;
  for (int i = N; i; i /= 10)
    Sn += i % 10;

  puts((N % Sn > 0)? "No":"Yes");
}