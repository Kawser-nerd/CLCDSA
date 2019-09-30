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
#define MAX_N (100000)
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  int count[MAX_N + 1];
  fill(count, count + MAX_N + 1, 0);

  int ans = 1;
  int s = 0, t = 0;
  while(s < n){
    while(t < n && count[a[t]] == 0){
      count[a[t]]++;
      ++t;
    }
    ans = max(ans, t - s);
    count[a[s]]--;
    s++;
  }

  cout << ans << endl;

  return 0;
}