#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#include <algorithm>
#include <numeric>
#include <cassert>

using namespace std;

char s[10000];

int Abs(int x) {
  return (x < 0) ? -x : x;
}

int main(void) {
  scanf("%s", s);
    
  int n = strlen(s);
  
  vector<vector<int>> d(2);
  int at = 0, sum = 0;
  for (int i = 0; i <= n; i++) {
    if (s[i] == 'F') {
      sum++;
    } else {
      d[at].push_back(sum);
      at ^= 1;
      sum = 0;
    }
  }

  int x, y;
  scanf("%i %i", &x, &y);
  
  if (s[0] == 'F') {
    x -= d[0][0];
    d[0].erase(begin(d[0]));
  }
    
  vector<int> targets = {x, y};
  for (int a = 0; a < 2; a++) {
    auto& s = d[a];    
    int m = int(s.size());
        
    vector<vector<int>> f(m+1, vector<int>(2*n+1));
    f[0][n] = 1;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j<= 2*n; j++) {
        if (f[i][j]) {
          if (j + s[i] <= 2*n) f[i+1][j+s[i]] = 1;
          if (j - s[i] >= 0) f[i+1][j-s[i]] = 1;
        }
      }
    }
    
    if (!f[m][n+targets[a]]) {
      puts("No");
      return 0;
    }
  }
  
  puts("Yes");
  
  return 0;
}