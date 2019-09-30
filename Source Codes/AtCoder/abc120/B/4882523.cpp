#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, char const *argv[]) {
  int A, B, K, num=100;
  std::cin >> A >> B >> K;
  while(K > 0){
    if(A%num == 0 && B%num == 0){
      K--;
      num--;
    }else num--;
  }
  std::cout << num + 1<< '\n';
  return 0;
}