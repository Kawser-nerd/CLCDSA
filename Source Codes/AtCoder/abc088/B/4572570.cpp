#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
  int N = 0;
  std::cin >> N;
  std::vector<int> A(N, 0);
  for (int i = 0; i < A.size(); i++) {
    int a = 0;
    std::cin >> a;
    A[i] = a;
  }
  int Alice = 0;
  int Bob = 0;
  int max = 0;

  size_t maxIndex = 0;
  int counter = 0;
  while (counter < N) {
    if (counter % 2 == 0 ) {
      max = *std::max_element(A.begin(), A.end());
      maxIndex = std::distance(A.begin(), std::max_element(A.begin(), A.end()));
      Alice += A[maxIndex];
      A[maxIndex] = 0;
      counter++;
    } else {
      max = *std::max_element(A.begin(), A.end());
      maxIndex = std::distance(A.begin(), std::max_element(A.begin(), A.end()));
      Bob += A[maxIndex];
      A[maxIndex] = 0;
      counter++;
    }
  }
  std::cout << Alice - Bob << std::endl;
  return 0;
}