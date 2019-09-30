#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  int n,k; cin >> n >> k;
  vector<int> h(n);
  for(int i=0;i<n;i++) cin >> h[i];
  sort(h.begin(), h.end());
  int ans=1000000001;
  for(int i=0;i+k-1<n;i++) ans = ans > h[i+k-1] - h[i] ? h[i+k-1] - h[i] : ans;
  cout << ans << endl;
  return 0;
}