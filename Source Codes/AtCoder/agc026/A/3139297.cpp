#include <iostream>
using namespace std;

int main() {
  int n, a[100];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  
  int count = 0;
  
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i - 1]) {
      a[i] = 10000 + i;
      count++;
    }
  }
  
  cout << count << endl;
}