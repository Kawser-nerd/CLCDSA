#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
  int n;
  cin >> n;
  string query = "";
  int mx = 0, q, p;
  for (int i=1; i<n; ++i) {
    int p = i+1;
    query += "? " + to_string(1) + " " + to_string(p);
    cout << query << endl;
    int res;
    cin >> res;
    if (res > mx) {
      mx = res;
      q = i+1;
    }
    query = "";
  }

  int ans = 0;
  for (int i=0; i<n; ++i) {
    if (i+1==q) continue;
    int p = i+1;
    query += "? " + to_string(q) + " " + to_string(p);    
    cout << query << endl;
    int res;
    cin >> res;
    ans = max(res, ans);
    query = "";
  }

  cout << "! " << to_string(ans) << endl;
  return 0;
}