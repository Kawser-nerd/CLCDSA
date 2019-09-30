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

  string a, b;
  cin >> a >> b;

  int ans = -INF_INT;
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 6; j++){
      string c(a), d(b);
      if(j < 3) c[j] = (char)('0' + i);
      else d[j - 3] = (char)('0' + i);
      if(c[0] == '0' || d[0] == '0') continue;
      ans = max(ans, stoi(c) - stoi(d));
    }
  }

  cout << ans << endl;

  return 0;
}