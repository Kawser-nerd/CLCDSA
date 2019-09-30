#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define rep(i,n) for(int (i)=0;(i) < (n); (i)++)

vector<int> tb(200001);
int main(){
  int n,k; cin >> n >> k;
  vector<int> v(n); rep(i,n) cin >> v[i];
  rep(i,200001) tb[i] = 0;
  rep(i,n) tb[v[i]]++;
  sort(tb.begin(),tb.end(), greater<int>());
  int ans=0;
  for(int i=k;i<200001;i++) ans+=tb[i];
  cout << ans << endl;
  return 0;
}