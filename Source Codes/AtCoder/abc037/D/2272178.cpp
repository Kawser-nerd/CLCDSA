#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <vector>

#define rep(i, s, N) for(int i = s; i < N; i++)
#define Yes(result) if (result) std::cout << "Yes" << '\n'
#define No(result) if (!result) std::cout << "No" << '\n'
#define resetarr(val, arr) for(int i = 0; i < sizeof(arr) / 4; i++){ arr[i] = val; }

const int H = 1100, W = 1100;
int map[H][W];
int memo[H][W];
int h = H, w = W;
const int DIVISOR = pow(10,9) + 7;

int rec(int x, int y) {
  if(x > h || x < 1 || y > w || y < 1) return 0;
  if(memo[x][y] != 0) {
    return memo[x][y];
  }
  long long ans = 1;
  if (map[x+1][y] > map[x][y]) ans += rec(x+1, y);
  if (map[x-1][y] > map[x][y]) ans += rec(x-1, y);
  if (map[x][y+1] > map[x][y]) ans += rec(x, y+1);
  if (map[x][y-1] > map[x][y]) ans += rec(x, y-1);
  ans %= DIVISOR;
  memo[x][y] = ans;
  return ans;
}

int main(int argc, char const *argv[]) {
  std::cin >> h >> w;
  rep(i, 1, h+1){
    rep(j, 1, w+1){
      std::cin >> map[i][j];
    }
  }
  rep(i, 1, h+1){
    resetarr(0, memo[i]);
  }

  long long sum = 0;
  rep(i, 1, h+1){
    rep(j, 1, w+1){
      sum += rec(i, j);
    }
  }

  std::cout << sum % DIVISOR << '\n';

  return 0;
}