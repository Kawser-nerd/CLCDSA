#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
  int N, H;
  std::cin >> N >> H;

  std::vector<int> A(N), B(N);

  for (int i = 0; i < N; i++) {
    std::cin >> A[i] >> B[i];
  }

  std::sort(A.begin(), A.end(), std::greater<int>());
  std::sort(B.begin(), B.end(), std::greater<int>());

  int h = 0, times = 0;



  for (auto b : B) {
    if (b > A[0]) {
      h += b;
      times++;

      if (h >= H) {
        break;
      }
    }
  }

  if (h < H) {
    times += (H - h + A[0] - 1) / A[0];
  }

  std::cout << times << std::endl;
}