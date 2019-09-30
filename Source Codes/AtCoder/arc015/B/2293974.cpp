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
  double m1[n], m2[n];
  for(int i = 0; i < n; i++){
    cin >> m1[i] >> m2[i];
  }

  int count[6];
  fill(count, count + 6, 0);
  for(int i = 0; i < n; i++){
    if(m1[i] >= 35) ++count[0];
    if(m1[i] >= 30 && m1[i] < 35) ++count[1];
    if(m1[i] >= 25 && m1[i] < 30) ++count[2];
    if(m2[i] >= 25) ++count[3];
    if(m2[i] < 0 && m1[i] >= 0) ++count[4];
    if(m1[i] < 0) ++count[5];
  }

  string ans = to_string(count[0]);
  for(int i = 1; i < 6; i++){
    ans += " " + to_string(count[i]);
  }

  cout << ans << endl;

  return 0;
}