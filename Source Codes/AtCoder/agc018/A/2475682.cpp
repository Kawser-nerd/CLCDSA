#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a,int b){
  while(a!=0){
    if(a<b) swap(a,b);
    a %= b;
  }
  return b;
}

int main(){
  int n,k;
  cin >> n >> k;
  int a[n];
  int ma=0;
  for(int i=0;i<n;i++) {cin >> a[i] ; ma = max(ma,a[i]);};
  int g = a[0];
  for(int i=1;i<n;i++) g = gcd(g,a[i]);
  if(ma>=k&&k%g==0) cout << "POSSIBLE" << endl;
  else cout << "IMPOSSIBLE" << endl;
  return 0;
}