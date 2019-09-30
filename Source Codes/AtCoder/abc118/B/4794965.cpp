#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  
  vector<int> c(m);
  
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    
    for (int j = 0; j < k; j++) {
      int a;
      cin >> a;
      
      c[a-1]++;
    }
  }
  
  cout << count(c.begin(), c.end(), n) << endl;
}