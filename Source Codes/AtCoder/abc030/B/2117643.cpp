#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  double hour = (n >= 12)? n-12: n;
  hour *= 30;
  hour += 0.5*m;
  double minute = m*6;
  double a = min(abs(hour - minute), 360 - abs(hour - minute));

  cout << a << endl;
}