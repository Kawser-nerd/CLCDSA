#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int main(){
  int a;
  cin >> a;

  int FUCK = 0;
  int tmp;

  for (int i=1; i<=1000; i++) {
    for (int j=2; j<=1000; j++) {
      tmp = pow(i, j);
      if (FUCK < tmp && tmp <= a) FUCK = tmp;
      else if (tmp > a) break;
    }
  }

  cout << FUCK << endl;
}