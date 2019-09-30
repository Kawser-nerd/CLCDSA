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

  int n, k;
  cin >> n >> k;
  int t[n];
  for(int i = 0; i < n; i++){
    cin >> t[i];
  }

  int ans = -1;
  int sum = t[0] + t[1];
  for(int i = 2; i < n; i++){
    sum += t[i];
    if(sum < k){
      ans = i + 1;
      break;
    }
    sum -= t[i - 2];
  }

  cout << ans << endl;

  return 0;
}