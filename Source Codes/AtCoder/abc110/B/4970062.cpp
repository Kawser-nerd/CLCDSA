#include <iostream>
#include <string>
#include <vector>
#include <deque>
#define range(i, r) for(int i=0;i<r;i++)
#define ranges(i, l, r) for(int i=l;i<r;i++)
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
#define MODs 1000000007;
#define MODn 1000000009;
typedef long long int ll;
using namespace std;

int main(int argc, char const *argv[]) {
  int N, M, X, Y;
  std::cin >> N >> M >> X >> Y;
  std::vector<int> x(N+1);
  std::vector<int> y(M+1);
  range(i, N) std::cin >> x[i];
  range(i, M) std::cin >> y[i];
  x[N] = X;
  y[M] = Y;
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  if(x[N]<y[0]) std::cout << "No War" << '\n';
  else std::cout << "War" << '\n';
  return 0;
}