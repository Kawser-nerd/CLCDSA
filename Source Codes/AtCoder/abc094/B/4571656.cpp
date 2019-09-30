#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N = 0;
  int M = 0;
  int X = 0;
  std::cin >> N >> M >> X;
  std::vector<int> A(0, 0);

  for (int i = 0; i < M; i++) {
    int a = 0;
    cin >> a;
    A.push_back(a);
    //std::cout << A[i] << std::endl;
  }

  int right_cost = 0;
   int left_cost = 0 ;
  int i = 0;
   if(X < A[0]){
   left_cost=0;
     right_cost=M;
   }else if(X > A[M-1]){
   right_cost=M;
     left_cost=0;
   }else{
  for (;;) {
    if (A[i] < X && A[i + 1] > X) {
      break;
    }
    i += 1;
  }
      right_cost = M - (i+1 );
  left_cost = i+1 ;
   }
 
 //std::cout << left_cost << std::endl;
 //  std::cout << right_cost << std::endl;
  std::cout << min(left_cost, right_cost) << std::endl;
  return 0;
}