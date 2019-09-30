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

bool gb(int i){
  return i == 4 || i == 6 ||
  i == 9 || i == 11;
}
bool gc(int i){
  return i == 2;
}
bool ga(int i){
  return !gb(i) && !gc(i);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int x, y;
  cin >> x >> y;

  if((ga(x) && ga(y)) ||
    (gb(x) && gb(y)) ||
    (gc(x) && gc(y))){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }

  return 0;
}