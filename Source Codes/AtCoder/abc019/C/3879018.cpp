#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector< int > a(n);
  for (int i=0;i<n;++i) {
    cin >> a[i];
    while (a[i] % 2 == 0) {
      a[i] >>= 1;
    }
  }
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  cout << a.size() << endl;
  
  return 0;
}