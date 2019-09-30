#include <iostream>
#include <queue>
using namespace std;
#define ll long long
queue<ll> bi, bj;
ll stand[50][50];
ll h, w;
char s[50][50];

void bfs (ll length) {
  ll vx[4] = {1, -1, 0, 0};
  ll vy[4] = {0, 0, 1, -1};
  stand[0][0] = 1;
  while (bi.empty() == false) {
    ll i = bi.front();
    ll j = bj.front();
    for (ll p = 0; p < 4; p++) {
      ll x = vx[p] + j;
      ll y = vy[p] + i;  
      if (x >= 0 && x < w && y >= 0 && y < h) {
        if (stand[y][x] == 0 && s[y][x] == '.') {
          stand[y][x] = stand[i][j] + 1;
          bi.push(y);
          bj.push(x);
        }  
      }
    }
    bi.pop();
    bj.pop();
  }
}

int main () {
  cin >> h >> w;
  ll black = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> s[i][j];  
      stand[i][j] = 0;
      if (s[i][j] == '#') {
        black++;  
      }
    }  
  }  
  bi.push(0);
  bj.push(0);
  bfs(1);
  if (stand[h - 1][w - 1] == 0) {
    cout << - 1 << endl;
    return 0;  
  }
  cout << h * w - stand[h - 1][w - 1] - black << endl;

}