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
  int t[n];
  for(int i = 0; i < n; i++){
    cin >> t[i];
  }

  int sum = 0;
  for(int i = 0; i < n; i++){
    sum += t[i];
  }

  int ans = INF_INT;
  for(int s = 0; s < (1 << n); s++){
    int ss = 0;
    for(int i = 0; i < n; i++){
      if((s & (1 << i)) != 0){
        ss += t[i];
      }
    }
    ans = min(ans, max(ss, sum - ss));
  }

  cout << ans << endl;

  return 0;
}