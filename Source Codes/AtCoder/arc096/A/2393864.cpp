#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int main(){
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  int res = A*X + B*Y;
  int tmp;

  if  (X == Y) {
    cout << ((res >= X*C*2)? X*C*2: res) << endl;
    return 0;
  }

  tmp = (min(X, Y) * 2 * C) + (((X>Y)? A: B) * abs(X-Y));
  if (tmp < res) res = tmp;

  tmp = max(X, Y) * 2 * C;
  if (tmp < res) res = tmp;



  cout << res << endl;
}