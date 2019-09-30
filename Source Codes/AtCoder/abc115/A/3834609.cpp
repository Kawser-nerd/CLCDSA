#include<iostream>
using namespace std;

int main() {
  int d = 0;
  cin >> d;
  cout << "Christmas";
  for (int i = 0; i < 25 - d; i++) {
    cout << " Eve";
  }
  cout << endl;
  return 0;
}