#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
#define ll long long int

int main(){
  int n,M = 0,sum = 0; cin >> n;
  vector < int > p(n);
  for ( int i = 0; i < n; ++i ) {
    cin >> p[i];
    sum += p[i];
    M = max(p[i],M);  
  }
  cout << sum - M / 2 << endl;
  return 0;
}