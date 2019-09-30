#include <iostream>
#include <set>
#include <map>
#include <utility>
#define ll long long
using namespace std;
set<ll> box[100001];
map<pair<ll, ll>, ll> size;
ll length[100001];

void dfs (ll i, ll pa = -1) {
  for (auto j : box[i]) {
    if (j != pa) {
      length[j] = length[i] + size[make_pair(i, j)];
      dfs(j, i);
    }
  }
}

int main () {
  ll n;
  cin >> n;
  for (ll i = 0; i < n - 1; i++) {
    ll s, ss, sss;
    cin >> s >> ss >> sss;
    box[s].insert(ss);  
    box[ss].insert(s);
    size[make_pair(s, ss)] = sss;  
    size[make_pair(ss, s)] = sss;  
  }
  ll q, k;
  cin >> q >> k;
  length[k] = 0;
  length[0] = 0;
  dfs(k, -1);
  ll ans[q];
  for (int i = 0; i < q; i++) {
    int s, ss;
    cin >> s >> ss;
    ans[i] = length[s] + length[ss];   
  }
  for (int i = 0; i < q; i++) {
    cout << ans[i] << endl;  
  }
    
}