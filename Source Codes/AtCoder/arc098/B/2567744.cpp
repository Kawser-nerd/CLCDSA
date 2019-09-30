#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)

int main() {
  int n;
  cin >> n;
  vector<long long> xs(n);
  rep(i, n) cin>>xs[i];

  vector<int> skips(n);
  int sk = 0;
  for(int i=n-1; i>=0; --i) {
    sk = xs[i]==0 ? sk+1 : 0;
    skips[i] = sk;
    //cout << sk << endl;
  }

  //for(auto x : skips) cout << x << " ";

  long ans = 0;
  rep(i, n) {
    long long sum=0;
    long long xors=0;
    for (int j=i; j<n; ++j) {
      if (skips[j] > 0) {
	ans += skips[j];
	j += skips[j]-1;
	continue;
      }
      sum += xs[j];
      xors^= xs[j];
      if (sum!=xors) break;
      ans++;
    }
    //cout << i << endl;
  }

  cout << ans << endl;
}