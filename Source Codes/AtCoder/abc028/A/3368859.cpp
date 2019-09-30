#include <iostream>

using namespace std;

int main() { 
  int n;
  cin >> n;
  if (n <= 59) {
    cout << "Bad";
  } else if (n >= 60 && n <= 89) {
    cout << "Good";
  } else if (n >= 90 && n <= 99) {
    cout << "Great";
  } else if (n == 100) {
    cout << "Perfect";
  } 
  cout << endl;
}