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

  int n, m;
  cin >> n >> m;
  int a[m];
  for(int i = 0; i < m; i++){
    cin >> a[i];
  }

  set< int > s;
  vector< int > b;
  for(int i = m - 1; i >= 0; i--){
    if(s.find(a[i]) == s.end()){
      b.push_back(a[i]);
    }
    s.insert(a[i]);
  }

  for(int i = 1; i <= n; i++){
    if(s.find(i) == s.end()){
      b.push_back(i);
    }
  }

  string ans;
  for(int i: b){
    ans += to_string(i) + "\n";
  }

  cout << ans;

  return 0;
}