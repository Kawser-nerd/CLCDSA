#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#define INF_INT (INT_MAX / 2)
#define INF_LONG (LONG_MAX / 2)
//#define DEBUG true
#define DEBUG false
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int a, b, c;
  cin >> a >> b >> c;

  if(a % 2 == 1 || b % 2 == 1 || c % 2 == 1){
    cout << 0 << endl;
    return 0;
  }

  if(a == b && b == c){
    cout << -1 << endl;
    return 0;
  }

  int count = 0;
  while(a % 2 == 0 && b % 2 == 0 && c % 2 == 0){
    int na = b / 2 + c / 2;
    int nb = a / 2 + c / 2;
    int nc = a / 2 + b / 2;
    a = na; b = nb; c = nc;
    ++count;
  }

  cout << count << endl;

  return 0;
}