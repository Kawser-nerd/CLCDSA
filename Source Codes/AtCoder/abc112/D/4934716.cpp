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
#define MODs (int)1000000007;
#define MODn (int)1000000009;
typedef long long int ll;
using namespace std;

int main(int argc, char const *argv[]) {
  int N, M, ans=1, yobi=1;
  std::cin >> N >> M;

  ranges(i, 1, max((int)sqrt(M)+1, N+1)){
    if(M%i==0){
      if(i>=N){
        ans = M/i;
        break;
      }else{
        if(M/i >= N){
          ans = max(ans, i);
        }
      }
    }
  }
  std::cout << ans << '\n';
  return 0;
}