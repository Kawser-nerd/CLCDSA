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

typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  ll x[n], y[n];
  for(int i = 0; i < n; i++){
    cin >> x[i] >> y[i];
  }

  int count = 0;
  for(int i = 0; i < n; i++){
    for(int j = i + 1; j < n; j++){
      for(int k = j + 1; k < n; k++){
        ll px = x[j] - x[i];
        ll py = y[j] - y[i];
        ll qx = x[k] - x[i];
        ll qy = y[k] - y[i];
        ll s = (px * qy - py * qx);
        if(s != 0 && s % 2 == 0) ++count;
      }
    }
  }

  cout << count << endl;

  return 0;
}