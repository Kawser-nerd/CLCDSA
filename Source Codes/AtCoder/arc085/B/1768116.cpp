#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
  int n, z, w;
  cin >> n >> z >> w;
  
  int a[2000];
  for(int i = 0; i < n; i++) {
   	cin >> a[i]; 
  }
  
  cout << (n == 1 ? abs(a[0] - w) : max(abs(a[n - 1] - w), abs(a[n - 1] - a[n - 2]))) << endl;
}