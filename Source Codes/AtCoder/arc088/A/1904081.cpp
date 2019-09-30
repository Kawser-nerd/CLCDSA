#include <cstdio>
#include <iostream>

using namespace std;

int main(void){
  long long x, y, res = 0;
  cin >> x >> y;
  while (x <= y) {
    x = x << 1;
    res++;
  }
  cout << res << endl;
  return 0;
}