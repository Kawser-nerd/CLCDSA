#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <cmath>
#define range(i, r) for(int i=0;i<r;i++)
#define ranges(i, l, r) for(int i=l;i<r;i++)
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
#define MODs 1000000007;
#define MODn 1000000009;
typedef long long int ll;
using namespace std;

int ret[7] ={0, 2, 3, 5, 8, 13, 21};
int amida(int num){
  if(num <=0){
    return 1;
  }
  return ret[num];
}

int main(int argc, char const *argv[]) {
  int H, W, K;
  std::cin >> H >> W >> K;
  vvl dp = vv(H+1, W+2, 0, ll);
  if(W==1){
    std::cout << 1 << '\n';
    return 0;
  }
  if(W==2){
    dp[1][1] = dp[1][2] = 1;
  }else{
    dp[1][1] = amida(W-2);
    dp[1][2] = amida(W-3);
  }
  ll a, b, c;
  ranges(i, 2, H+1){
    ranges(j, 1, W+1){
      a = (dp[i-1][j]*amida(j-2)*amida(W-j-1))%MODs;
      b = (dp[i-1][j-1]*amida(j-3)*amida(W-j-1))%MODs;
      c = (dp[i-1][j+1]*amida(j-2)*amida(W-j-2))%MODs;
      dp[i][j] = (a+b+c)%MODs;
    }
  }
  std::cout << dp[H][K] << endl;
  return 0;
}