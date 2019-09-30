#include <algorithm>
#include <list>
#include <iostream>
#include <vector>
 
#define unless(cond) if (!(cond))
 
using namespace std;
 
typedef long long int lli;
typedef unsigned long long ull;
 
int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  int n;
  while (cin >> n) {
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    list<int> x;
    for (int i = 0; i < n; ++i) {
      if (x.size() % 2) x.push_front(a[i]);
      else x.push_back(a[i]);
    }
    if (n % 2) reverse(x.begin(), x.end());
    bool f = false;
    for (auto i = x.begin(); i != x.end(); ++i) {
      if (f) cout << ' ';
      f = true;
      cout << *i;
    }
    cout << endl;
  }
  
  return 0;
}