#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define range(i, l, r) for(int i=l;i<r;i++)
using namespace std;
int main(int argc, char const *argv[]) {
  long long N, M;
  long long summ=0;
  std::cin >> N >> M;
  std::vector<std::vector<long long> > AB(N, std::vector<long long>(2));
  range(i, 0, N){
    std::cin >> AB[i][0] >> AB[i][1];
  }
  std::sort(AB.begin(), AB.end());
  range(i, 0, N){
    if(AB[i][1] < M){
      summ+=AB[i][0]*AB[i][1];
      M-=AB[i][1];
    }else{
      summ+=AB[i][0]*M;
      break;
    }
  }
  std::cout << summ << '\n';

  return 0;
}