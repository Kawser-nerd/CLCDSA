#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
  int N, K;
  cin >> N >> K;
  vector<vector<int> > g(N);
  for(int i = 0; i < N; ++i) {
    int t, d;
    cin >> t >> d; --t;
    g[t].push_back(d);
  }
  vector<int> basic, addit;
  for(int i = 0; i < N; ++i) {
    sort(g[i].begin(), g[i].end(), greater<int>());
    if(g[i].size() >= 1) {
      basic.push_back(g[i].front());
    }
    if(g[i].size() >= 2) {
      addit.insert(addit.end(), g[i].begin() + 1, g[i].end());
    }
  }
  sort(basic.begin(), basic.end(), greater<int>());
  sort(addit.begin(), addit.end(), greater<int>());
  int lb = basic.size(), la = addit.size();
  vector<long long> sbasic(lb + 1), saddit(la + 1);
  for(int i = 0; i < lb; ++i) sbasic[i + 1] = sbasic[i] + basic[i];
  for(int i = 0; i < la; ++i) saddit[i + 1] = saddit[i] + addit[i];
  long long ans = 0;
  for(int i = 0; i <= K && i <= lb; ++i) {
    if(K - i <= la) {
      ans = max(ans, (long long)(i) * i + sbasic[i] + saddit[K - i]);
    }
  }
  cout << ans << endl;
  return 0;
}