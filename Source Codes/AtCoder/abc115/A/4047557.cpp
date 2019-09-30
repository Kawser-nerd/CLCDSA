#include <iostream>

using namespace std;

int main() {
  int D;
  cin >> D;
  cout << "Christmas ";
  for (int i = 0; i < (25 - D); ++i) {
    cout << "Eve";
    if (i < (25 - D) - 1) {
    	cout << " ";
    }
  }
  cout << endl;
}