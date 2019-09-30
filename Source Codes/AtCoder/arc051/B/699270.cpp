#include <iostream>
using namespace std;

int main() {
  int K;
  int a, b;
  cin >> K;
  a = 1, b = 1;
  for(int i = 0; i < K; i++) {
    int tmp = 0;
    tmp = a + b;
    a = b;
    b = tmp;
  }
  cout << b << " " << a << endl;
}