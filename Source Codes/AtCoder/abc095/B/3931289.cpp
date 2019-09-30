#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int N, X;
  int mm = 1000;
  int sum = 0;
  cin >> N >> X;

  for (int i = 0; i < N; i++) {
    int M;
    cin >> M;
    mm = min(mm, M);
    sum += M;
  }

  printf("%d", N + (X - sum) / mm);
}