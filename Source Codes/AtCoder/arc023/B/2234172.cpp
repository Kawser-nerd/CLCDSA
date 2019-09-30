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

typedef tuple< int, int, int > ti;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int r, c, d;
  cin >> r >> c >> d;
  int a[r][c];
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      cin >> a[i][j];
    }
  }

  int dist[r][c];
  for(int i = 0; i < r; i++){
    fill(dist[i], dist[i] + c, INF_INT);
  }

  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, -1, 0, 1};
  priority_queue< ti > q;
  q.push(make_tuple(0, 0, 0));
  while(!q.empty()){
    int dd = -get< 0 >(q.top());
    int i = get< 1 >(q.top());
    int j = get< 2 >(q.top());
    q.pop();
    if(!(dd <= d && dd < dist[i][j])) continue;
    dist[i][j] = dd;
    for(int k = 0; k < 4; k++){
      int ni = i + dy[k];
      int nj = j + dx[k];
      if(!((0 <= ni && ni < r) && (0 <= nj && nj < c))) continue;
      q.push(make_tuple(-(dd + 1), ni, nj));
    }
  }

  int ans = 0;
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      if((dist[i][j] <= d) && ((d - dist[i][j]) % 2 == 0)){
        ans = max(ans, a[i][j]);
      }
    }
  }

  cout << ans << endl;

  return 0;
}