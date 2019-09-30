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

  double sx, sy;
  cin >> sx >> sy;
  int n;
  cin >> n;
  double x[n], y[n];
  for(int i = 0; i < n; i++){
    cin >> x[i] >> y[i];
  }

  double mi = INF_LONG;
  for(int i = 0; i < n; i++){
    int j = (i + 1) % n;
    double bx = x[j] - x[i], by = y[j] - y[i];
    double px = sx - x[i], py = sy - y[i];
    double d = (bx * py - by * px) / sqrt(bx * bx + by * by);
    mi = min(mi, d);
  }

  printf("%07lf\n", mi);
  return 0;
}