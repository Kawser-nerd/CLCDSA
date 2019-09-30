#include <iostream>
using namespace std;

int main () {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i <= n; i++) {
    int z = i;
    int y = -2 * n - 2 * z + m;
    int x = 3 * n - m + z;
    if (x >= 0 && y >= 0 && z >= 0) {
      cout << x << " " << y << " " << z << endl;
      break;  
    }  
    if (i == n) {
      cout << "-1 -1 -1" << endl;  
    }
  }    
}