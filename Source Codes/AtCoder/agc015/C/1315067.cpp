#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MAX_N = 2000;
const int MAX_M = 2000;

int N, M, Q;
int node[MAX_N][MAX_M];
int edge_h[MAX_N][MAX_M];
int edge_v[MAX_N][MAX_M];

int cumsum[MAX_N+1][MAX_M+1];
int cumsum_h[MAX_N+1][MAX_M+1];
int cumsum_v[MAX_N+1][MAX_M+1];

int main()
{
  ios::sync_with_stdio(false);
  cin >> N >> M >> Q;
  std::string s;
  for (int i = 0; i < N; i++)
  {
    cin >> s;
    for (int j = 0; j < M; j++)
    {
      node[i][j] = s[j] - '0';
    }
  }
  
  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
      if (j + 1 < M){
        if (node[i][j] == 1 && node[i][j+1] == 1) {
          edge_h[i][j] = 1;
        } else {
          edge_h[i][j] = 0;
        }
      }
      if (i > 0){
        if (node[i][j] == 1 && node[i-1][j] == 1) {
          edge_v[i][j] = 1;
        } else {
          edge_v[i][j] = 0;
        }
      }
    }
  }

  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
      cumsum[i+1][j+1] = node[i][j] + cumsum[i][j+1] + cumsum[i+1][j] - cumsum[i][j];
      cumsum_h[i+1][j+1] = edge_h[i][j] + cumsum_h[i][j+1] + cumsum_h[i+1][j] - cumsum_h[i][j];
      cumsum_v[i+1][j+1] = edge_v[i][j] + cumsum_v[i][j+1] + cumsum_v[i+1][j] - cumsum_v[i][j];
    }
  }

  int y1, x1, y2, x2;
  int sum_node, sum_edge_h, sum_edge_v;
  for (int i = 0; i < Q; i++){
    cin >> y1 >> x1 >> y2 >> x2;
    sum_node = cumsum[y2][x2] - cumsum[y1-1][x2] - cumsum[y2][x1-1] + cumsum[y1-1][x1-1];
    sum_edge_h = cumsum_h[y2][x2-1] - cumsum_h[y1-1][x2-1] - cumsum_h[y2][x1-1] + cumsum_h[y1-1][x1-1];
    sum_edge_v = cumsum_v[y2][x2] - cumsum_v[y1-1+1][x2] - cumsum_v[y2][x1-1] + cumsum_v[y1-1+1][x1-1];
    cout << sum_node - sum_edge_h - sum_edge_v << endl;
  }
  return 0;
}