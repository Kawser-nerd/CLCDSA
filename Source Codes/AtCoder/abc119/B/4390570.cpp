#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
using namespace std;
#define ll long long int

int main(){ 
  int n;cin >> n;
  double ans = 0;
  for(int i = 0; i < n; ++i){
    double x;string u;
    cin >> x >> u;
    if(u == "BTC") x *= 380000;
    ans += x;  
  }
  
  cout << ans << endl;
  return 0;
}