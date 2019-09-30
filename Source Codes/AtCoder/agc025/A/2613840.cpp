#include <iostream>
using namespace std;
int main() {
  int N,ans;
  cin >> N;
  if (N==10 || N==100 || N==1000 || N==10000 || N==100000) {
    ans = 10;
  } else {
    ans = N/10000 + (N%10000)/1000 + (N%1000)/100 + (N%100)/10 + (N%10);
  }
  cout << ans << endl;
  return 0;
}