#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main () {
  stack<int> ns, ew;
  string h;
  cin >> h;
  int n, e, w, s;
  n = 0;
  e = 0;
  w = 0;
  s = 0;
  for (int i = 0; i < h.size(); i++) {
  	if (h[i] == 'N') {
      n++;
    }
    if (h[i] == 'S') {
      s++;
    }
    if (h[i] == 'W' ){
      w++;
    }
    if (h[i] == 'E') {
      e++;
    }
  }
  if (n > 0 && s == 0) {
    cout << "No" << endl;
    return 0;
  }
  if (n == 0 && s > 0) {
    cout << "No" << endl;
    return 0;
  }
  if (e > 0 && w == 0) {
    cout << "No" << endl;
    return 0;
  }
  if (e == 0 && w > 0) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
}