#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int upper = 1;
  while (upper * 2 <= N) {
    upper *= 2;
  }
  cout << upper << '\n';
  return 0;
}