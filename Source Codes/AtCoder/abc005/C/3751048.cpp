#include <iostream>
using namespace std;

int main () {
  int t, n;
  cin >> t >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];  
  }  
  int m;
  cin >> m;
  int b[m];
  for (int i = 0; i < m; i++) {
    cin >> b[i];  
  }
  int itr = 0;
  bool ok = false;
  for (int i = 0; i < m; i++) {
    while (1) {
      if (itr == n) {
        cout << "no" << endl;
        ok = true;
        break;  
      }
      if (b[i] >= a[itr] && b[i] - t <= a[itr]) {
        itr++;
        break;  
      }    
      else {
        itr++;  
      }
    }    
    if (ok) {
      break;  
    }
    if (i == m - 1) {
      cout << "yes" << endl;
      break;  
    }
 
  }
}