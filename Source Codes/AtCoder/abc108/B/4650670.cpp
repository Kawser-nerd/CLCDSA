#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;
#define ll long long int


int main() {
  int x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  int a_x = x2 - x1;
  int a_y = y2 - y1;

  cout << x2 - a_y << " " << y2 + a_x << " ";
  cout << x1 - a_y << " " << y1 + a_x << endl;  
  return 0;
}