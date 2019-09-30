#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long int ll;

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

vector<int> par,r;

void init(int n){
  par.resize(n);
  r.resize(n);
  for(int i = 0; i < n; i++)
  {
    par[i] = i;
    r[i] = 0;
  }
}

int find(int x){
  if (par[x] == x){
    return x;
  }else{
    return find(par[x]);
  }
}

void unite(int x,int y){
  x = find(x);
  y = find(y);

  if(x == y){
    return;
  }else if(r[x] < r[y]){
    par[x] = y;
  }else{
    par[y] = x;
    if(r[x] == r[y]) r[x]++;
  }
}

bool same(int x,int y){
  return find(x) == find(y);
}



int main()
{
  int n,m;
  cin >> n >> m;
  vector<int> p(n),x(m),y(m);
  for(int i = 0; i < n; i++) cin >> p[i];
  for(int i = 0; i < m; i++) cin >> x[i] >> y[i];

  init(n);

  for(int i = 0; i < m; i++){
    unite(x[i],y[i]);
  }

  int sol = 0;
  for(int i = 0; i < n; i++){
    if(same(i+1,p[i])) sol++;
  }

  cout << sol << endl;


  return 0;
}