#include <iostream>
#include <string>
#include <vector>
#include <deque>
#define range(i, r) for(int i=0;i<r;i++)
#define ranges(i, l, r) for(int i=l;i<r;i++)
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
typedef long long int ll;
using namespace std;

int main(int argc, char const *argv[]) {
  int N, M;
  std::cin >> N >> M;
  std::vector<int> lis(M);;
  range(i, M){
    std::cin >> lis[i];
  }
  sort(lis.begin(), lis.end());
  reverse(lis.begin(), lis.end());
  vvi dp = vv(N+1, M + 1, 0, int);
  vvi usable = vv(M, 2, 0, int);
  int mach[9] = {2, 5, 5, 4, 5, 6, 3, 7, 6};
  range(i, M){
    usable[i][0] = lis[i];
    usable[i][1] = mach[lis[i] - 1];
    //1: number 2: the number of match
  }
  ranges(i, 1, N+1){
    dp[i][M] = -1;
  }
  ranges(i, 1, N+1){
    range(j, M){
      if(usable[j][1] > i) {
        continue;
      }else if(dp[i - usable[j][1]][M]== -1){
        continue;
      }else{
        if(dp[i-usable[j][1]][M]+1 > dp[i][M]){
          range(k, M){
            dp[i][k] = dp[i - usable[j][1]][k];
          }
          dp[i][j]++;
          dp[i][M] = dp[i-usable[j][1]][M]+1;
        }
      }
    }
  }
  range(i, M){
    range(j, dp[N][i]){
      std::cout << usable[i][0];
    }
  }
  return 0;
}