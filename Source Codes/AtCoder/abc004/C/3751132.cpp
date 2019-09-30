#include <iostream>
#include <string.h>
using namespace std;

int main () {
  string h = "123456";
  long long n;
  cin >> n;
  string ans[30];
  for (int i = 0; i <= 29; i++) {
    swap(h[i % 5], h[i % 5 + 1]);
    ans[(i + 1) % 30] = h;
  }  
  cout << ans[n % 30] << endl;
}