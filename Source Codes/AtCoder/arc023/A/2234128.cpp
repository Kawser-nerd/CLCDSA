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

int number(int y, int m, int d){
  if(m == 1 || m == 2){
    --y;
    m += 12;
  }
  return 365 * y + (y / 4) - (y / 100) + (y / 400) +
    ((306 * (m + 1)) / 10) + d - 429;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int y, m, d;
  cin >> y >> m >> d;

  int ans = number(2014, 5, 17) - number(y, m, d);

  cout << ans << endl;

  return 0;
}