#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
ll l[N], r[N];
priority_queue<ll> q;
int x, y, z, n;
struct Node{
  int gold, silver, bronze;
  bool operator < (const Node& rh) const{
    if(gold-silver != rh.gold-rh.silver)
      return gold-silver < rh.gold-rh.silver;
    return silver > rh.silver;
  }
}node[N];

ll solve(){
  sort(node, node+n);
  ll sum = 0;
  while(!q.empty()) q.pop();
  for(int i = 0; i < y; i++){
    q.push(node[i].bronze - node[i].silver);
    sum += node[i].silver;
  }
  for(int i = y; i < y+z; i++){
    l[i] = sum;
    sum += node[i].silver;
    if(q.top() > node[i].bronze - node[i].silver){
      sum += q.top();
      q.pop();
      q.push(node[i].bronze - node[i].silver);
    }
    else sum += node[i].bronze - node[i].silver;
  }
  l[y+z] = sum;
  sum = 0;
  while(!q.empty()) q.pop();
  for(int i = n-1; i >= y+z; i--){
    q.push(node[i].bronze - node[i].gold);
    sum += node[i].gold;
  }
  r[y+z] = sum;
  for(int i = y+z-1; i >= y; i--){
    sum += node[i].gold;
    if(q.top() > node[i].bronze-node[i].gold){
      sum += q.top();
      q.pop();
      q.push(node[i].bronze-node[i].gold);
    }
    else sum += node[i].bronze-node[i].gold;
    r[i] = sum;
  }
  ll ans = 0;
  for(int i = y; i <= y+z; i++) ans = max(ans, l[i]+r[i]);
  return ans;
}

int main(){
  scanf("%d%d%d", &x, &y ,&z);
  n = x + y + z;
  for(int i = 0; i < n; i++)
  scanf("%d%d%d", &node[i].gold, &node[i].silver, &node[i].bronze);
  ll ans = solve();
  printf("%lld\n", ans);
}