#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string>
using namespace std;

int main(){
  int x, y, z, w;
  cin >> x >> y >> z >> w;
  cout << y - w + z << ' ' << w+z-x << ' ' << y-w+x << ' ' << y+z-x <<endl;
  return 0;
}