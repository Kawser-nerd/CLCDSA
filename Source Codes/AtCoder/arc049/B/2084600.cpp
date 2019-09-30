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
#define INF_DOUBLE (INT_MAX)
//#define DEBUG true
#define DEBUG false
#define MAX_N 100000
using namespace std;

int n;
int x[MAX_N], y[MAX_N], c[MAX_N];

bool fx(double k){
  double left = -INF_DOUBLE, right = INF_DOUBLE;
  for(int i = 0; i < n; i++){
    left = max(x[i] - k / c[i], left);
    right = min(x[i] + k / c[i], right);
    if(left > right) return false;
  }
  return left <= right;
}
bool fy(double k){
  double left = -INF_DOUBLE, right = INF_DOUBLE;
  for(int i = 0; i < n; i++){
    left = max(y[i] - k / c[i], left);
    right = min(y[i] + k / c[i], right);
    if(left > right) return false;
  }
  return left <= right;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> x[i] >> y[i] >> c[i];
  }

  double low = 0, high = INF_DOUBLE;
  for(int i = 0; i < 100; i++){
    double mid = (low + high) / 2.0;
    if(fx(mid)) high = mid;
    else low = mid;
  }
  double ans = high;
  low = 0, high = INF_DOUBLE;
  for(int i = 0; i < 100; i++){
    double mid = (low + high) / 2.0;
    if(fy(mid)) high = mid;
    else low = mid;
  }
  ans = max(ans, high);

  printf("%04lf\n", ans);

  return 0;
}