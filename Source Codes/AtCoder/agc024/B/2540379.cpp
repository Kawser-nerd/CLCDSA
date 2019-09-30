#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int n;
  cin >> n;
  std::vector<int> positions(n+1);
  for(int i=0; i<n; ++i) {
    int x;
    cin >> x;
    positions[x] = i;
  }

  int longest=0;
  for(int x=1; x<=n; ) {
    int pos = positions[x];
    int i=1;
    for(; i+x<=n; ++i) {
      if(pos > positions[x+i]) break;
      pos = positions[x+i];
    }
    longest = max(longest, i);
    x += i;
  }

  int ans = n-longest;

  cout << ans << endl;
}