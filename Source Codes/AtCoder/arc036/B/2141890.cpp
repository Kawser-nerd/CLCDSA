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
  int h[n];
  for(int i = 0; i < n; i++){
    cin >> h[i];
  }

  if(n == 1){
    cout << 1 << endl;
    return 0;
  }

  int ans = 1;
  int s = 0;
  while(true){
    int u = s;
    while(u + 1 < n && h[u] < h[u + 1]){
      ++u;
    }
    while(u + 1 < n && h[u] > h[u + 1]){
      ++u;
    }
    ans = max(ans, u - s + 1);
    s = u;
    if(s == n - 1) break;
  }

  cout << ans << endl;

  return 0;
}