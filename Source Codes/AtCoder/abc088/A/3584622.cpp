#include <iostream>
using namespace std;

int main() {
  int N, A, rest;
  cin >> N >> A;
  rest = N % 500;
  cout << (rest <= A ? "Yes\n" : "No\n");

  return 0;
}