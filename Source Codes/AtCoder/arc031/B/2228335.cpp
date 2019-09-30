#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(i,a,n) for(int i = (a); i < (n); ++i)
#define REP(i,n) FOR(i,0,n)
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)

#define INF 100000000

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

bool visited[10][10];
char c[10][10];

void dfs(int x, int y) {
  visited[x][y] = true;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i]; int ny = y + dy[i];
    if (0 <= nx && nx < 10 && 0 <= ny && ny <10 && c[nx][ny] == 'o' && !visited[nx][ny]) {
      dfs(nx, ny);
    }
  }
}

int main() {
  REP(i,10) REP(j,10) cin >> c[i][j];
  REP(i,10) REP(j,10) {
    REP(x,10) REP(y,10) visited[x][y] = false;
    bool f = true;
    dfs(i,j);
    REP(x,10) REP(y,10) if (c[x][y] == 'o' && !visited[x][y]) f = false;
    if (f) { cout << "YES" << endl; return 0; }
  }
  cout << "NO" << endl;
  return 0;
}