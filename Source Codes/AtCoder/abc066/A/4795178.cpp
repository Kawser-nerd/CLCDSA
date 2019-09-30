#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  vector<int> a(3);
  cin >> a[0];
  cin >>a[1];
  cin >>a[2];
  sort(a.begin(),a.end());
  cout << a[0]+a[1] <<endl;
   return 0;
}