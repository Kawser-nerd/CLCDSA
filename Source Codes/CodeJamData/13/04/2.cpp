#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool check(
  const map<int, int> &init_keys,
  const vector<pair<int, vector<int> > > &boxes,
  const vector<bool> &used
  ) {
  map<int,int> keys = init_keys;
  map<int, vector<vector<int> > > bs;

  for (int i=0;i<boxes.size();++i)
    if (!used[i])
      bs[boxes[i].first].push_back(boxes[i].second);

  map<int, int> saw;
  map<int, int> q;
  for (auto it = keys.begin(); it != keys.end(); ++it)
    if (it->second > 0)
      q.insert(*it);

  while(!q.empty()) {
    int curk = q.begin()->first;
    int curv = q.begin()->second;
    q.erase(q.begin());
    if (saw.count(curk)) continue;

    const vector<vector<int> > &vvs=bs[curk];
    saw[curk]+=curv;
    saw[curk]-=vvs.size();
    for (int i=0; i<vvs.size();++i)
      for (int j=0;j<vvs[i].size();++j)
        ++q[vvs[i][j]];
  }

  if (saw.size() < bs.size()) return false;
  for (auto it = saw.begin(); it != saw.end(); ++it)
    if (it->first < 0) return false;

  return true;
}

int main()
{
  int cases; cin >> cases;
  for (int cn = 1; cn <= cases; ++cn) {
    int k, n; cin>>k>>n;
    map<int, int> keys;
    for (int i=0; i<k; ++i) {
      int t; cin>>t; --t;
      keys[t]++;
    }
    vector<pair<int, vector<int> > > boxes;
    for (int i=0; i<n; ++i) {
      int t; cin>>t; --t;
      int m; cin>>m;
      vector<int> ks;
      for (int j=0;j<m;++j) {
        int tt;
        cin >> tt; --tt;
        ks.push_back(tt);
      }
      boxes.push_back(make_pair(t, ks));
    }

    vector<bool> used(n, false);
    vector<int> ans;
    for (int i=0;i<n;i++) {
      for (int j=0;j<n;j++) {
        if (used[j]) continue;
        if (keys[boxes[j].first] <= 0) continue;

        keys[boxes[j].first]--;
        for (int k=0;k<boxes[j].second.size();++k)
          keys[boxes[j].second[k]]++;
        used[j] = true;

/*
        cout << "keys ";
        for (auto it = keys.begin(); it != keys.end(); ++it)
          cout << ", " << it->first << ": " << it->second;
        cout << endl;
        cout << "chk: " << i << ", " << j << ": " << check(keys, boxes, used) << endl;
*/
        
        if (check(keys, boxes, used)) {
          ans.push_back(j);
          goto _next;
        }
        keys[boxes[j].first]++;
        for (int k=0;k<boxes[j].second.size();++k)
          keys[boxes[j].second[k]]--;
        used[j] = false;
      }
      break;
    _next:;
    }

    cout << "Case #" << cn << ":";
    if (ans.size() == n) {
      for (int i=0; i<n; ++i)
        cout << " " << ans[i] + 1;
      cout << endl;
    }
    else cout << " IMPOSSIBLE" << endl;
  }
  return 0;

  return 0;
}