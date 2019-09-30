#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int main(){
  double a, b, c, d;
  cin >> a >> b >> c >> d;
  double taka = b/a;
  double ao = d/c;
  if (ao == taka) cout << "DRAW" << endl;
  else if(ao > taka) cout << "AOKI" << endl;
  else cout << "TAKAHASHI" << endl;
}