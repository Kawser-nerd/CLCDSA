#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int ce[100][100];
int fl[100][100];
int usable[100][100][4];
int slow[100][100][4];

int main() {
  int t;
  scanf("%d", &t);

  for(int z = 1; z <= t; z++) {
    const int INF = 1000000000;
    int start = -INF;
    int h, n, m;
    
    scanf("%d %d %d", &h, &n, &m);
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
	scanf("%d", &ce[i][j]);
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
	scanf("%d", &fl[i][j]);
    
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};

    memset(usable, 0x3f, sizeof usable);
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
	for(int k = 0; k < 4; k++) {
	  int ni = i + di[k], nj = j + dj[k];
	  if(ni < 0 || ni+1 > n) continue;
	  if(nj < 0 || nj+1 > m) continue;

	  // Condition 2
	  if(ce[ni][nj] - fl[i][j] < 50) {
	    continue;
	  }
	  // Condition 3
	  if(ce[ni][nj] - fl[ni][nj] < 50) {
	    continue;
	  }
	  // Condition 4
	  if(ce[i][j] - fl[ni][nj] < 50) {
	    continue;
	  }

	  // Time for condition 1
	  int height = ce[ni][nj] - 50;
	  usable[i][j][k] = h - height;
	  if(usable[i][j][k] <= 0)
	    usable[i][j][k] = -INF;

	  height = fl[i][j] + 20;
	  slow[i][j][k] = h - height;
	  if(slow[i][j][k] <= 0) 
	    slow[i][j][k] = -INF-1;
	}

    priority_queue<pair<int, pair<int, int> > > q;
    int dist[100][100], visited[100][100];
    memset(dist, 0x3f, sizeof dist);
    memset(visited, 0, sizeof visited);

    dist[0][0] = start;
    q.push(make_pair(-start, make_pair(0, 0)));

    while(!q.empty()) {
      pair<int, int> v = q.top().second; q.pop();
      int ci = v.first, cj = v.second;

      if(visited[ci][cj]) continue;
      visited[ci][cj] = true;

      int cost;
      for(int k = 0; k < 4; k++) {
	int ni = ci + di[k], nj = cj + dj[k];
	int curtme = max(dist[ci][cj], usable[ci][cj][k]);
	
	if(curtme == 0x3f3f3f3f) continue;
	if(curtme > slow[ci][cj][k])
	  cost = 100;
	else
	  cost = 10;

	if(curtme + cost < dist[ni][nj]) {
	  dist[ni][nj] = curtme + cost;
	  q.push(make_pair(-dist[ni][nj], make_pair(ni, nj)));
	}
      }
    }
  
    printf("Case #%d: %.1lf\n", z, max(0, dist[n-1][m-1])/10.0);
  }
}
