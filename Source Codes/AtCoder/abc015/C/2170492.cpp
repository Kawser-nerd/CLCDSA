#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int N, K;
vector<vector<int>> t;

bool dfs(int n, int res) {
  if (n == N) return res == 0;
  for (int i=0; i<K; i++) {
    if (dfs(n+1, res^t[n][i])) return true;
  }
  return false;
}

int main(){
  cin >> N >> K;
  t = vector<vector<int>>(N, vector<int>(K));
  for (int i=0; i<N; i++)
    for (int k=0; k<K; k++)
      cin >> t[i][k];

  bool res = false;
  for (int i=0; i<N; i++) {
    if (dfs(0, 0)) {
      res = true;
      break;
    }
  }

  

  cout << ((res)? "Found": "Nothing") << endl;
}