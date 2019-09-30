#include <iostream>
using namespace std;

int main() {
  string S;
  cin >> S;
  int len = S.size();
  cout << S[0] << len - 2 << S[len - 1] << '\n';
  return 0;
}