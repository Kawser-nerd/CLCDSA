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
  int c[n];
  for(int i = 0; i < n; i++){
    cin >> c[i];
  }

  bool all = true;
  for(int i = 0; i < n; i++){
    if(c[i] != c[(i + 1) % n]){
      all = false;
      break;
    }
  }
  if(all){
    cout << -1 << endl;
    return 0;
  }

  int mx = 0;

  if(c[0] == c[n - 1]){
    int a = 0;
    while(c[a] == c[a + 1]){
      ++mx;
      ++a;
    }
    ++mx;
    int b = n - 1;
    while(c[b] == c[b - 1]){
      ++mx;
      --b;
    }
    ++mx;
  }

  int s = 0;
  while(s < n){
    int t = s;
    while(t + 1 < n && c[t] == c[t + 1]){
      ++t;
    }
    mx = max(mx, t - s + 1);
    s = t + 1;
  }

  if(mx < 3){
    cout << 0 << endl;
  }
  else{
    cout << ((mx + 1) / 2) << endl;
  }

  return 0;
}