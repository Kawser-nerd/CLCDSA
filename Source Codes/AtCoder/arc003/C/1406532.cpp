#include <algorithm>
#include <bitset>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

// c++11
#include <array>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

#define mp make_pair
#define mt make_tuple
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

const int INF = 1 << 29;
const double EPS = 1e-9;
const ll MOD = 1000000007;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
const int MAX_N = 505;
int N,M;
char board[MAX_N][MAX_N];
int sy,sx;
int gy,gx;
bool visited[MAX_N][MAX_N];
double num_pow[10][MAX_N * MAX_N];
void calc(){

  for (int i = 1; i < 10; i++){
    num_pow[i][0] = i;
    for (int j = 1; j < MAX_N * MAX_N; j++){
      num_pow[i][j] = num_pow[i][j-1] * (double)0.99;
    }
  }
}
bool check(const double low_light){
  queue<tuple<pii, int>> que;
  //init
  que.emplace(mt(mp(sy, sx), 0));
  memset(visited, false, sizeof(visited));
  while (not que.empty()){
    auto p = que.front();
    que.pop();
    pii pos = get<0>(p);
    int py,px;
    int cnt;
    py = pos.first;
    px = pos.second;
    cnt = get<1>(p);
    if (visited[py][px]){
      continue;
    }
    visited[py][px] = true;
    for (int k = 0; k < 4; k++){
      int ny,nx;
      ny = py + dy[k];
      nx = px + dx[k];

      if (ny < 0 or ny >= N or nx < 0 or nx >= M){
        continue;
      }
      if (board[ny][nx] == '#'){
        continue;
      }
      if (board[ny][nx] == 's'){
        continue;
      }
      if (board[ny][nx] == 'g'){
        return true;
      }
      if (visited[ny][nx]){
        continue;
      }
      int num = board[ny][nx] - '0';
      double cost = num_pow[num][cnt + 1];
      if (cost < low_light){
        continue;
      }

      que.emplace(mt(mp(ny, nx), cnt + 1));
    }
  }

  return false;
}
int main() {
  cin >> N >> M;
  sy = gy = -1;
  sx = gx = -1;

  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
      cin >> board[i][j];
      if (board[i][j] == 's'){
        sy = i;
        sx = j;
      }

      if (board[i][j] == 'g'){
        gy = i;
        gx = j;
      }
    }
  }
  calc();
  if (not check(-114514)){
      cout << -1 << endl;
      return 0;
  }
  double left = -1;
  double right = 10;
  bool ok = false;
  for (int i = 0; i < 200; i++){
    double med = (right + left) * 0.5;

    if (check(med)){
      ok = true;
      left = med;
    }else{
      right = med;
    }
  }
  if (not ok){
    cout << -1 << endl;
    return 0;
  }
  printf("%.13lf\n", left);
  return 0;
}