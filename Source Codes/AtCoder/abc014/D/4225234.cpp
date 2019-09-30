#include <iostream>
#include <set>
#include <queue>
using namespace std;

set<int> dp[100001];
queue<int> box, de;
int stand[100001];
int deep[100001];

int main () {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    dp[x].insert(y);
    dp[y].insert(x);  
  }  
  int next[20][100001];
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j <= 100000; j++) {
      next[i][j] = 0;  
    }  
  }
  // 1????????.
  next[0][1] = -1;
  for (int i = 0; i <= 100000; i++) {
    stand[i] = 0;
    deep[i] = 0;  
  }
  box.push(1);
  de.push(1);
  while (box.empty() == false) {
    int front = box.front();
    int d1 = de.front();
    stand[front] = 1;
    deep[front] = d1;
    for (auto j : dp[front]) {
      if (stand[j] == 0) {
        box.push(j);
        de.push(d1 + 1);
        next[0][j] = front;  
      }  
    }  
    box.pop();
    de.pop();
  }
  int q;
  cin >> q;
  int a[q], b[q];
  for (int i = 0; i < q; i++) {
    cin >> a[i] >> b[i];  
  }

  // ?????????
  for (int i = 1; i < 20; i++) {
    for (int j = 1; j <= n; j++) {
      if (next[i - 1][j] > 0) {
        next[i][j] = next[i - 1][next[i - 1][j]];    
      }
      else {
        next[i][j] = -1;  
      }
    }  
  }

  // LCA????
  for (int  i = 0; i < q; i++) {
    int x = a[i];
    int y = b[i];
    if (deep[x] > deep[y]) {
      swap(x, y);  
      swap(a[i], b[i]);
    }
    // x????deep[y] - deep[x]????
    int sub = deep[y] - deep[x];
    int itr = 0;
    while (sub != 0) {
      if (sub % 2 == 1) {
        y = next[itr][y];    
      }      
      itr++;
      sub = sub >> 1;
    }
    if (x == y) {
      cout << deep[b[i]] - deep[a[i]] + 1 << endl;  
    }
    else {
      for (int j = 19; j >= 0; j--) {
        if (next[j][x] != next[j][y]) {
          x = next[j][x];
          y = next[j][y];    
        }    
      }  
      int lca = next[0][x];
      cout << deep[a[i]] - deep[lca] + deep[b[i]] - deep[lca] + 1 << endl;
    }
  }
}