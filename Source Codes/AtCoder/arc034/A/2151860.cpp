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
  int a[n], b[n], c[n], d[n], e[n];
  for(int i = 0; i < n; i++){
    cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];
  }

  double mx = 0;
  for(int i = 0; i < n; i++){
    mx = max(mx, 110.0 / 900.0 * e[i] + 
        a[i] + b[i] + c[i] + d[i]);
  }

  printf("%05lf\n", mx);

  return 0;
}