#include <iostream>
#include <string>
#include <vector>
#define range(i, l, r) for(int i=l;i<r;i++)
using namespace std;

int main(int argc, char const *argv[]) {
  int N, M, C, summ, count=0;
  std::cin >> N >> M >> C;
  std::vector<int> B(M);
  for(int i=0;i<M;i++) std::cin >> B[i];
  std::vector<std::vector<int> > As(N, vector<int>(M));
  range(i, 0, N){
    range(j, 0, M){
      std::cin >> As[i][j];
    }
  }
  for(int i=0;i<N;i++) {
    summ = 0;
    for(int j=0;j<M;j++){
      summ += As[i][j] * B[j];
    }
    summ += C;
    if(summ>0)count++;
  }
  std::cout << count << '\n';


  return 0;
}