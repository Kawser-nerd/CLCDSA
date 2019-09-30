#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  if (N < 1000) {
    cout << "ABC" << endl;
  } else {
    cout << "ABD" << endl;
  }
  return 0;
}