#include <iostream>
#include <string.h>
using namespace std;

int main () {
  int n;
  cin >> n;
  string h;
  cin >> h;
  string hh;
  cin >> hh;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (h[j] != hh[j - i]) {
        break;    
      }    
      if (j == n - 1) {
        ans = n - i;
        break;  
      }
    }  
    if (ans != 0) {
      break;  
    }
  }
  cout << (h + hh.substr(ans, n - ans)).size() << endl;
}