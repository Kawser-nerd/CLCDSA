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

typedef pair< int, int > pii;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int h, w;
  cin >> h >> w;
  string s[MAX_H];
  for(int i = 0; i < h; i++){
    cin >> s[i];
  }

  if(h == w && h == 1){
    cout << "Second" << endl;
    return 0;
  }

  bool visited[h][w];
  bool defined[h][w];
  bool mark[h][w];
  for(int i = 0; i < h; i++){
    fill(visited[i], visited[i] + w, false);
    fill(defined[i], defined[i] + w, false);
    fill(mark[i], mark[i] + w, false);
  }

  const int di[3] = {0, 1, 1};
  const int dj[3] = {1, 0, 1};

  queue< pii > que;
  que.push(make_pair(0, 0));
  visited[0][0] = true;
  while(!que.empty()){
    int i = que.front().first, j = que.front().second; que.pop();
    bool all = true;
    for(int k = 0; k < 3; k++){
      int ni = i + di[k], nj = j + dj[k];
      if(!((0 <= ni && ni < h) && (0 <= nj && nj < w)) ||
          s[ni][nj] == '#') continue;
      all = false;
      if(!visited[ni][nj]){
        visited[ni][nj] = true;
        que.push(make_pair(ni, nj));
      }
    }
    if(all) defined[i][j] = true;
  }

  set< pii > undefined;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(visited[i][j] && !defined[i][j])
        undefined.insert(make_pair(i, j));
    }
  }

  while(!undefined.empty()){
    set< pii > removed;
    for(pii p: undefined){
      int i = p.first, j = p.second;
      bool all_defined = true;
      bool exist = false;
      for(int k = 0; k < 3; k++){
        int ni = i + di[k], nj = j + dj[k];
        if(!((0 <= ni && ni < h) && (0 <= nj && nj < w)) ||
            s[ni][nj] == '#') continue;
        if(!defined[ni][nj]) all_defined = false;
        if(defined[ni][nj] && !mark[ni][nj]) exist = true;
      }
      if(exist || all_defined){
        mark[i][j] = exist;
        defined[i][j] = true;
        removed.insert(p);
      }
    }
    for(pii p: removed){
      undefined.erase(p);
    }
  }

  if(mark[0][0]) cout << "First" << endl;
  else cout << "Second" << endl;

  return 0;
}