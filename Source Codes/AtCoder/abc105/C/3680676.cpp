#include<iostream>
#include<vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector <int> digits;
  int d = N;
  if (d == 0) {
    cout << 0 << endl;
    exit(0);
  }
  while(d != 1) {
    if(abs(d) % 2 == 1) {
      d -= 1;
      digits.push_back(1);
    } else {
      digits.push_back(0);
    }
    d /= -2;
  }
  digits.push_back(1);
  reverse(digits.begin(), digits.end());
  for(int di: digits) {
    cout << di; 
  }
  cout << endl;
  return 0;
}