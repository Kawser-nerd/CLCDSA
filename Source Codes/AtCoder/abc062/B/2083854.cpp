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
#define MAX_H 100
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int h, w;
  cin >> h >> w;
  string t[MAX_H];
  for(int i = 0; i < h; i++){
    cin >> t[i];
  }

  string ans;
  for(int i = 0; i < w + 2; i++){
    ans.push_back('#');
  }
  ans.push_back('\n');
  for(int i = 0; i < h; i++){
    ans.push_back('#');
    ans += t[i];
    ans.push_back('#');
    ans.push_back('\n');
  }
  for(int i = 0; i < w + 2; i++){
    ans.push_back('#');
  }
  ans.push_back('\n');

  cout << ans << endl;

  return 0;
}