#include <iostream>
#include <string>
#include <vector>
#include <deque>
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
  //cin.tie(0);
  //ios::sync_with_stdio(false);
  ll N, M, tmp, count;
  std::cin >> N >> M;
  vvl ken = vv(M, 3, 0, ll);
  vvl ID = vv(M, 2, 0, ll);
  range(i, M) {
    std::cin >> ken[i][1] >> ken[i][0];
    ken[i][2] = i;
  }
  sort(ken.begin(), ken.end());
  range(i, M){
    tmp = ken[i][1];
    ken[i][1] = ken[i][0];
    ken[i][0] = tmp;
  }
  sort(ken.begin(), ken.end());
  tmp = 0;
  range(i, M){
    if(tmp != ken[i][0]){
      count = 1;
      tmp = ken[i][0];
      ID[i][1] = ken[i][0] * 1000000 + count;
      ID[i][0] = ken[i][2];
    }else{
      count += 1;
      ID[i][1] = ken[i][0] * 1000000 + count;
      ID[i][0] = ken[i][2];
    }
  }
  sort(ID.begin(), ID.end());
  int zero;
  range(i, M) {
    zero = 12 - to_string(ID[i][1]).size();
    std::cout << string(zero, '0') << ID[i][1] << '\n';
  }
  return 0;
}