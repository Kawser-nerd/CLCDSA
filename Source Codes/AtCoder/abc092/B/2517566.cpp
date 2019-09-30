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
  int d, x;
  cin >> d >> x;
  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  int ans = x;
  for(int i = 0; i < n; i++){
    int y = 1;
    while(y <= d){
      ++ans;
      y += a[i];
    }
  }

  cout << ans << endl;

  return 0;
}