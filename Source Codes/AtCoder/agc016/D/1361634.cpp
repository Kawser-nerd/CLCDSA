#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int u[108000];
int done[108000];
int dig[108000];
int cnt;

void ng(){
  cout << -1 << endl;
  exit(0);
}

int r(int x){
  if(x == u[x])return x;
  return u[x] = r(u[x]);
}

void unite(int x, int y){
  x = r(x);
  y = r(y);
  if(x != y)u[x] = y;
}

int n;

int main(){
  cin >> n;
  for(int i = 0;i < 108000;i++)u[i] = i;
  vector<int> a(n+1), b(n+1), c, d;
  a[n] = 0;
  for(int i = 0;i < n;i++){
    cin >> a[i];
    a[n] ^= a[i];
  }
  b[n] = 0;
  for(int i = 0;i < n;i++){
    cin >> b[i];
    b[n] ^= b[i];
  }
  
  c = a;
  d = b;
  sort(c.begin(), c.end());
  sort(d.begin(), d.end());
  if(c != d){
    ng();
  }

  c.erase(unique(c.begin(), c.end()), c.end());

  for(int i = 0;i <= n;i++){
    a[i] = lower_bound(c.begin(), c.end(), a[i]) - c.begin();
    b[i] = lower_bound(c.begin(), c.end(), b[i]) - c.begin();
  }
  

  for(int i = 0;i <= n;i++){
    if(a[i] == b[i])continue;
    unite(a[i], b[i]);
    dig[a[i]]++;
    cnt++;
  }
  for(int i = 0;i <= n;i++){
    if(a[i] == b[i])continue;
    if(done[r(a[i])])continue;
    done[r(a[i])] = true;
    cnt++;
  }
  if(a[n] != b[n])cnt -= 2;
  else if(dig[a[n]] > 0)cnt--;
  cout << cnt << endl;
  return 0;
}