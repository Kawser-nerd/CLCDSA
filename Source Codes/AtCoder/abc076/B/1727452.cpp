#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  int ret = 1;
  while(N > 0 && ret < K){
    ret *= 2;
    N--;
  }
  while(N > 0){
    ret += K;
    N--;
  }
  cout << ret << endl;
  return 0;
}