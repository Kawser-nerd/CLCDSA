#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  vector<int>l(n);
  for(int i=0; i<n; i++)cin >> l[i];
  sort(l.rbegin(), l.rend());
  cout << accumulate(l.begin(), l.begin()+k, 0);
  return 0;
}