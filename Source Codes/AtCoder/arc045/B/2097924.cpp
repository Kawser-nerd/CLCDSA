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
#define MAX_N 300000
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  int s[m], t[m];
  for(int i = 0; i < m; i++){
    cin >> s[i] >> t[i];
    --s[i]; --t[i];
  }

  vector< int > a[MAX_N + 1];
  for(int i = 0; i < m; i++){
    a[s[i]].push_back(i + 1);
    a[t[i] + 1].push_back(-(i + 1));
  }

  set< int > must;
  set< int > cur;
  for(int i = 0; i <= n; i++){
    for(int j: a[i]){
      if(j < 0){
        cur.erase(-j - 1);
      }
      else{
        cur.insert(j - 1);
      }
    }
    if(cur.size() == 1){
      for(int j: cur){
        must.insert(j);
      }
    }
  }

  vector< int > ans;
  for(int i = 0; i < m; i++){
    if(must.find(i) == must.end()){
      ans.push_back(i + 1);
    }
  }

  string str;
  str += to_string(ans.size()) + "\n";
  for(int i: ans){
    str += to_string(i) + "\n";
  }

  cout << str;

  return 0;
}