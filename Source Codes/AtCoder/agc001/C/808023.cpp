#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int dp[2001][2001];
int sz[2001];
int tmp[2001];
int ans[2001];
vector<int> edge[2001];

int n, k, a, b;

void dfs(int x, int last = -1){

  dp[x][0] = 0;
  sz[x] = 1;
  for(int i = 0;i < edge[x].size();i++){
    int to = edge[x][i];
    if(to == last)continue;
    dfs(to, x);
    for(int j = 0;j < sz[x] + sz[to];j++)tmp[j] = 1 << 29;
    for(int j = 0;j < sz[x];j++){
      tmp[j] = min(tmp[j], dp[x][j] + sz[to]);
      for(int l = 0;l < sz[to];l++){
	if(j + l + 1 > k)continue;
	tmp[max(j, l + 1)] = min(tmp[max(j, l + 1)], dp[x][j] + dp[to][l]);
      }
    }
    sz[x] += sz[to];
    for(int j = 0;j < sz[x];j++)dp[x][j] = tmp[j];
  }
  ans[x] = 1 << 29;
  for(int j = 0;j < sz[x];j++)ans[x] = min(dp[x][j], ans[x]);
  ans[x] = n - 1 - (sz[x] - 1 - ans[x]);
}

int main(){
  cin >> n >> k;
  for(int i = 0;i < n-1;i++){
    cin >> a >> b;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  for(int i = 1;i <= n;i++)
    for(int j = 0;j <= k;j++)
      dp[i][j] = 1 << 29;
  dfs(1);
  
  int res = 1 << 29;
  for(int i = 1;i <= n;i++)res = min(res, ans[i]);
  
  cout << res << endl;
}