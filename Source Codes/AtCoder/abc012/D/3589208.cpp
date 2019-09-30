#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef vector<vector<int> > Matrix;

const int INF = 100000000;


void warshall_floyd(int n, Matrix &m, Matrix &m2) { 
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++)    
      for (int k = 0; k < n; k++){
        m[j][k] = min(m[j][k], (m[j][i] + m[i][k]));
        m2[j][k] = m[j][k];
      }
    }
}

int main() {
  int n, m;
  cin >> n >> m;
  Matrix d,d2;
  d = Matrix(n, vector<int>(n, INF));
  d2 = Matrix(n, vector<int>(n, INF));
  for (int i = 0; i < n; i++) d[i][i] = 0;
  for (int i = 0; i < m; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;
    d[from-1][to-1] = cost;
    d[to-1][from-1] = cost;
  }
  warshall_floyd(n,d,d2);
  int mi = INF;
  for(int i=0; i<n;i++){
    int ma = *max_element(d2[i].begin(), d2[i].end());
    mi = min(mi, ma);
  }
  cout << mi << endl;
  return 0;
}