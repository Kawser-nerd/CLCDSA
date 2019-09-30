#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>

using namespace std;
typedef pair<int, int> P;

#define INF (1 << 29)

vector<P> edge[108];
int n, m, ans;
int a[1080], b[1080], c[1080];
int dist[108];

void dijkstra(int s){
  for(int i = 0;i < n;i++)dist[i] = INF;
  dist[s] = 0;
  priority_queue<P, vector<P>, greater<P> > pq;
  pq.push(P(0,s));

  while(!pq.empty()){
    P tmp = pq.top();pq.pop();
    int d = tmp.first;
    int from = tmp.second;
    if(dist[from] < d)continue;
    for(int i = 0;i < edge[from].size();i++){
      int to = edge[from][i].first;
      int c = edge[from][i].second;
      if(dist[from] + c < dist[to]){
	dist[to] = dist[from] + c;
	pq.push(P(dist[to], to));
      }
    }
  }  
}

int main(){
  cin >> n >> m;
  for(int i = 0;i < m;i++){
    cin >> a[i] >> b[i] >> c[i];
    a[i]--,b[i]--;
    edge[a[i]].push_back(P(b[i], c[i]));
    edge[b[i]].push_back(P(a[i], c[i]));
  }

  for(int i = 0;i < m;i++){
    dijkstra(a[i]);
    if(dist[b[i]] != c[i])ans++;
  }
  cout << ans << endl;
  return 0;
}