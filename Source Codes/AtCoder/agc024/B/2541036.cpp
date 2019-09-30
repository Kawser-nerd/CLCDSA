#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<pair<int,int> > d;
  for(int i=0;i<n;i++){ 
    int a;
    cin >> a;
    d.push_back(make_pair(a,i));
  }
  sort(d.begin(),d.end());
  int ma = 1, now = 1;
  for(int i=1;i<n;i++){
  	if(d[i].second > d[i-1].second){now++;}
    else {now = 1;}
    if(now > ma) ma = now;
  }
  cout << n - ma << endl;
  return 0;
}