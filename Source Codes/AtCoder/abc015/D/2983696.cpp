#include <iostream>
#include <vector>
#include <utility>

using namespace std;
int main() {
  int W,N,K;
  cin >> W >> N >> K;

  vector<pair<int, int> >shot(N+1);

  for(int i = 1; i <= N; i++) {
    int a, b;
    cin >> a >> b;
    shot[i] = make_pair(a, b);
  }

  vector<vector<vector<int> > > h = vector<vector<vector<int> > >(K + 1, vector<vector<int> >(N + 1, vector<int>(W + 1, 0)));

  for(int j = 1; j <= N; j++) {
    for(int i = 1;i <= K; i++) {
      for(int k = 1; k <= W; k++) {
        int a = h[i][j-1][k];
        int b = k >= shot[j].first ? h[i-1][j-1][k - shot[j].first] + shot[j].second : 0;
        h[i][j][k] = a < b ? b : a;
        //cout << h[i][j][k] << "," << i << "," << j << "," << k << endl;
      }
    }
  }

  cout << h[K][N][W] << endl;
}