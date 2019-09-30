#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n; cin>>n;
  vector<int> a(n);
  map<int,int> mp;
  for(int i=0;i<n;++i){
    cin>>a[i];
    mp[a[i]];
  }
  
  int id=0;
  for(auto &&mi: mp){
    mi.second = id++;
  }
  
  for(int i=0;i<n;++i){
    cout << mp[a[i]] << endl;
  }
}