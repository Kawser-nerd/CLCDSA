#include <iostream>
using namespace std;

int main(){
  int x, t;
  cin >> x >> t;
  cout << max(x-t, 0);
  return 0;
}