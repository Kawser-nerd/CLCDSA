#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<set>
 
#define P 1000000007
 
using namespace std;
 
int fastpow(int e, int x) {
  if(x == 0) {
    return 1;
  }
  if(x % 2 == 0) {
    return fastpow(e*e, x / 2);
  } else {
    return e * fastpow(e, x - 1);
  }
}
 
int main() {
  int n;
  cin >> n;
  vector<long long> x;
  x.resize(n);
  for(int i = 0; i < n; i++) cin >> x[i];
 
  long long l;
  int q;
  cin >> l >> q;
  vector<pair<int, int>> query;
  query.resize(q);
  for(int i = 0; i < q; i++) {
    cin >> query[i].first >> query[i].second;
    if(query[i].first > query[i].second) {
      int tmp = query[i].first;
      query[i].first = query[i].second;
      query[i].second = tmp;
    }
    query[i].first--;
    query[i].second--;
  }
  vector<vector<long long>> path;
  path.resize(n);
  for(int i = 0; i < n; i++) {
    auto it = upper_bound(x.begin(), x.end(), x[i] + l);
    if(it - x.begin() == i) {
      path[i].push_back(i);
      continue;
    }
    it--;
    path[i].push_back(it - x.begin());
  }
  int cnt = 0;
  for(int k = 1; k < n; k *= 2) {
    for(int i = 0 ; i < n; i++) {
      path[i].push_back(path[path[i][cnt]][cnt]);
    }
    cnt++;
  }

  for(int i = 0; i < q; i++) {
    long long ans = 0;
    int now = query[i].first;
    while(true) {
      if(now >= query[i].second) break;
      auto p = lower_bound(path[now].begin(), path[now].end(), query[i].second);
      if(p == path[now].begin()) {
        ans++;
        break;
      }
      p--;
      ans += fastpow(2, p - path[now].begin());
      now = *p;
    }
    cout << ans << endl;
  }
 
  return 0;
}