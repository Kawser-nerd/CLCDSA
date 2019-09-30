#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(3*n);
  for(int i=0;i<3*n;i++) cin >> a[i];
  sort(a.begin(),a.end());
  long long int ans=0;
  for(int i=0;i<n;i++) ans = ans + a[(3*n)-(2*i)-2];
  cout << ans << endl;
  return 0;
}