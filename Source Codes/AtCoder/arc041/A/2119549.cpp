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

  int x, y, k;
  cin >> x >> y;
  cin >> k;

  if(y >= k){
    cout << (k + x) << endl;
  }
  else{
    cout << (y + x - (k - y)) << endl;
  }

  return 0;
}