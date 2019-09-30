#include <iostream>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  for (int i = 0; i <= w+1; i++) {
    cout << '#';
  }
  cout << endl;
  for (int i = 0; i < h; i++) {
    cout << '#';
    for (int j = 0; j < w; j++) {
      char a;
      cin >> a;
      cout << a;
    }
    cout << '#' << endl;
  }
  for (int i = 0; i <= w+1; i++) {
    cout << '#';
  }
  cout << endl;
}