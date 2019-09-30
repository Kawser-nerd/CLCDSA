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

string a[10];

void dfs(int i, int j, bool visited[10][10]){
  if(!((0 <= i && i < 10) && (0 <= j && j < 10))) return;
  if(visited[i][j] || a[i][j] == 'x') return;
  visited[i][j] = true;
  int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
  for(int k = 0; k < 4; k++){
    dfs(i + dy[k], j + dx[k], visited);
  }
}

bool connected(int si, int sj){
  bool visited[10][10];
  for(int k = 0; k < 10; k++){
    fill(visited[k], visited[k] + 10, false);
  }
  dfs(si, sj, visited);
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      if(a[i][j] == 'o' && !visited[i][j])
        return false;
    }
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  for(int i = 0; i < 10; i++){
    cin >> a[i];
  }

  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      if(a[i][j] == 'o') continue;
      a[i][j] = 'o';
      if(connected(i, j)){
        cout << "YES" << endl;
        return 0;
      }
      a[i][j] = 'x';
    }
  }
  cout << "NO" << endl;

  return 0;
}