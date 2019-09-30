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
#define MAX_N 500
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  string b[MAX_N];
  for(int i = 0; i < n; i++){
    cin >> b[i];
  }

  char ans[n][m];
  for(int i = 0; i < n; i++){
    fill(ans[i], ans[i] + m, '0');
  }
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {-1, 0, 1, 0};
  for(int i = 1; i < n - 1; i++){
    for(int j = 1; j < m - 1; j++){
      bool cir = true;
      char mi = '9';
      for(int k = 0; k < 4; k++){
        int nx = i + dx[k], ny = j + dy[k];
        if(b[nx][ny] == '0'){
          cir = false;
          break;
        }
        mi = min(mi, b[nx][ny]);
      }
      if(!cir) continue;
      ans[i][j] = mi;
      for(int k = 0; k < 4; k++){
        int nx = i + dx[k], ny = j + dy[k];
        b[nx][ny] = b[nx][ny] - (mi - '0');
      }
    }
  }

  string s;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      s.push_back(ans[i][j]);
    }
    s.push_back('\n');
  }

  cout << s;

  return 0;
}