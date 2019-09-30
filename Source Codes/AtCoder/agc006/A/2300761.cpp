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

  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;

  int ans = 2 * n;
  for(int i = 0; i < n; i++){
    bool match = true;
    for(int j = 0; i + j < n; j++){
      if(s[i + j] != t[j]){
        match = false;
        break;
      }
    }
    if(match) ans = min(ans, 2 * n - (n - i));
  }

  cout << ans << endl;

  return 0;
}