#include <iostream>
#include <string>
using namespace std;

int main() {
  string S;
  cin >> S;
  S[5] = S[13] = ' ';

  cout << S << endl;
  return 0;
}