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

  int x, y;
  cin >> x >> y;

  if(x == y){
    cout << 0 << endl;
    return 0;
  }

  int ans;
  if(x < y){
    if(x >= 0 || y <= 0){
      ans = y - x;
    }
    else if(abs(x) <= abs(y)){
      ans = 1 + y - (-x);
    }
    else{
      ans = (-y) - x + 1;
    }
  }
  else{
    if(y >= 0){
      ans = 1 + (-y) - (-x) + ((y != 0) ? 1 : 0);
    }
    else if(x <= 0){
      ans = (-y) - (-x) + 1 + ((x != 0) ? 1 : 0);
    }
    else if(abs(x) <= abs(y)){
      ans = (-y) - x + 1;
    }
    else{
      ans = 1 + y - (-x);
    }
  }

  cout << ans << endl;

  return 0;
}