#include <iostream>

using namespace std;
int N, M;
int field[100][100];
int rmax[100];
int cmax[100];
int main() {
  int T;
  cin >> T;
  for(int t = 1; t <= T; ++t) {
    cin >> N >> M;
    for(int i = 0; i < 100; ++i)
      rmax[i] = cmax[i] = 0;
    for(int r = 0; r < N; ++r)
      for(int c = 0; c < M; ++c) {
	cin >> field[r][c];
	rmax[r] = max(rmax[r], field[r][c]);
	cmax[c] = max(cmax[c], field[r][c]);
      }
    bool b = true;
    for(int r = 0; r < N; ++r) 
      for(int c = 0; c < M; ++c)
	if(field[r][c] < cmax[c] && field[r][c] < rmax[r])
	  b = false;
    cout << "Case #" << t << ": " << (b ? "YES" : "NO") << endl;
  }
  return 0;
}
