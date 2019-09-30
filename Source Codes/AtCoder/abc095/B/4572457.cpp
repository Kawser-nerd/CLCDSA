#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
int main() {
  int N = 0;
  int X = 0;
  std::cin >> N >> X;
  std::vector<int> M(N, 0);
  int answer = 0;
  for (int i = 0; i < M.size(); i++) {
    int a = 0;
    std::cin >> a;
    M[i] = a;
  }
  std::sort(M.begin(), M.end());
  int sum = std::accumulate(M.begin(), M.end(), 0);
  int tmp_X = X;
  int sum_counter = 0;

  if (tmp_X - sum >= 0) {
    tmp_X -= sum;
    sum_counter = 1;
  }
  int counter = 0;
  while (tmp_X > 0) {
    if (tmp_X - M[0] >= 0) {
      tmp_X -= M[0];
      counter++;
    } else {
      break;
    }
  }
  std::cout << counter + sum_counter * M.size() << std::endl;
  return 0;
}