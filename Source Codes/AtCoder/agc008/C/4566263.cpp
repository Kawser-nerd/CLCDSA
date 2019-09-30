#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  long i, o, t, j, l, s, z;
  cin >> i >> o >> t >> j >> l >> s >> z;
  if(i>=1 && j>=1 && l>=1)cout << o+max(2*(i/2+j/2+l/2), 2*((i-1)/2+(j-1)/2+(l-1)/2)+3);
  else cout << (i/2)*2+o+(j/2)*2+(l/2)*2;
  return 0;
}