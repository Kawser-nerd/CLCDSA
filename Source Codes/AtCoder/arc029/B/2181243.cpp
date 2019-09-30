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
#define MAX_N 5000
using namespace std;

double a, b;
int n;
double c[MAX_N], d[MAX_N];

bool check(double c, double d){
  double low = 0, high = M_PI / 2.0;
  for(int j = 0; j < 200; j++){
    double mid = (low + high) / 2.0;
    double h = a * cos(mid) + b * sin(mid);
    double w = b * cos(mid) + a * sin(mid);
    if(c >= h && d >= w) return true;
    if(h > c) high = mid;
    else low = mid;
  }
  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> a >> b;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> c[i] >> d[i];
  }

  if(a > b){
    double tmp = a; a = b; b = tmp;
  }

  string ans;
  for(int i = 0; i < n; i++){
    if((a <= c[i] && b <= d[i]) ||
        (a <= d[i] && b <= c[i])){
      ans += "YES\n";
      continue;
    }
    if(check(c[i], d[i]) || check(d[i], c[i]))
      ans += "YES\n";
    else ans += "NO\n";
  }

  cout << ans;

  return 0;
}