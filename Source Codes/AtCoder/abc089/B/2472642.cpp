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
#define MAX_N 100
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  string s[MAX_N];
  for(int i = 0; i < n; i++){
    cin >> s[i];
  }

  bool p, w, g, y;
  p = w = g = y = false;
  for(int i = 0; i < n; i++){
    if(s[i] == "P") p = true;
    else if(s[i] == "W") w = true;
    else if(s[i] == "G") g = true;
    else if(s[i] == "Y") y = true;
  }

  if(p & w & g & y) cout << "Four" << endl;
  else cout << "Three" << endl;

  return 0;
}