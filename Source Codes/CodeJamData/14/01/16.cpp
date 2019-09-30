#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <cstdlib>
#include <utility>

using namespace std;

int main() {
  int T; cin >> T;
  for(int t = 1; t <= T; t++) {
    map<int, int> mp;
    vector<int> results;
    for(int ii = 0; ii < 2; ii++) {
      int r; cin >> r;
      for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
          int x; cin >> x;
          if(i + 1 == r) {
            if(++mp[x] == 2) {
              results.push_back(x);
            }
          }
        }
      }
    }
    printf("Case #%d: ", t);
    if(results.size() == 1)  {
      printf("%d\n", results[0]);
    } else if(results.size() > 1) {
      printf("Bad magician!\n");
    } else {
      printf("Volunteer cheated!\n");
    }
  }
  return 0;
}
