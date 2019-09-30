#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;
typedef pair<int, int> P;

#define INF (1<<29)

int n, m, res;
int a[1080], b[1080], c[1080];
int dist[108][108];

int main(){
  cin >> n >> m;

  for(int i = 0;i < n;i++)
    for(int j = 0;j < n;j++)
      dist[i][j] = INF;
  
  for(int i = 0;i < m;i++){
    cin >> a[i] >> b[i] >> c[i];
    a[i]--,b[i]--;
    dist[a[i]][b[i]] = c[i];
    dist[b[i]][a[i]] = c[i];
  }

  for(int i = 0;i < n;i++)
    for(int j = 0;j < n;j++)
      for(int k = 0;k < n;k++)
	dist[j][k] = min(dist[j][i] + dist[i][k], dist[j][k]);
  
  for(int i = 0;i < m;i++){
    if(dist[a[i]][b[i]] != c[i])res++;
  }
  cout << res << endl;
  return 0;
}