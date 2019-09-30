#include <iostream>
#include <string>
#include <vector>
#include <deque>
#define range(i, r) for(int i=0;i<r;i++)
#define ranges(i, l, r) for(int i=l;i<r;i++)
typedef long long int ll;
using namespace std;

int main(int argc, char const *argv[]) {
  int N, M, maxx=0;
  std::cin >> N >> M;
  std::vector<int> X(M);
  range(i, M) std::cin >> X[i];
  sort(X.begin(), X.end());
  std::vector<int> XX(M-1);
  range(i, M-1) XX[i] = X[i+1] - X[i];
  sort(XX.begin(), XX.end());
  if(N >= M){
    std::cout << 0 << '\n';
  }else if(N == 1){
    std::cout << X[M-1] - X[0] << '\n';
  }else{
    maxx = X[M-1] - X[0];
    range(i, N-1) maxx -= XX[M-2-i];
    std::cout << maxx << '\n';
  }
  return 0;
}