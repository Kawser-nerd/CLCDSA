#include <iostream>
using namespace std;
typedef long long unsigned int ll;

int main() {

  int N,M;
  cin >> N;
  cin >> M;
  
  if (N>M){
    std::cout << N << endl;
    return 0;
  }else{
    std::cout << M << endl;
    return 0;
  }
}