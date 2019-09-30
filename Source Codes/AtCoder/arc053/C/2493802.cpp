#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long int ll;
int main(){
  int n;
  cin >> n;
  vector<pair<ll,ll> > lo,hi;
  for(int i=0;i<n;i++){
    ll a,b;
    cin >> a >> b;
    if(a<=b) lo.push_back(make_pair(a,b));
    else hi.push_back(make_pair(b,a));
  }
  sort(lo.begin(),lo.end());
  sort(hi.begin(),hi.end(), greater<pair<ll,ll> > ());
  ll now = 0, ma = 0;
  for(int i=0;i<lo.size();i++){
    ll a = lo[i].first, b = lo[i].second;
  	if(ma < now + a) ma = now + a;
    now = now + a - b;
  }
  for(int i=0;i<hi.size();i++){
    ll b = hi[i].first, a = hi[i].second;
  	if(ma < now + a) ma = now + a;
    now = now + a - b;
  }
  cout << ma << endl;
  return 0;
}