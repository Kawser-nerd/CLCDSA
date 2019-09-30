#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  long long x, y;
  cin >> x >> y;
  
  long long ans = 1LL << 60;
  
  if(y >= x) {
    ans = min(ans, y - x);
  }
  
  if(-y >= x) {
    ans = min(ans, -y - x + 1);
  }
  
  if(y >= -x) {
    ans = min(ans, y + x + 1);
  }
  
  if(-y >= -x) {
    ans = min(ans, -y + x + 2);
  }
  
  cout << ans << endl;
}