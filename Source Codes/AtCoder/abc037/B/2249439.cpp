#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <vector>

#define rep(i, s, N) for(int i = s; i < N; i++)
#define Yes(result) if (result) std::cout << "Yes" << '\n'
#define No(result) if (!result) std::cout << "No" << '\n'


int main(int argc, char const *argv[]) {
  int N = 110, Q = 110;
  int arr[N];
  for(int i = 0; i < N; i++){
    arr[i] = 0;
  }

  std::cin >> N >> Q;
  rep(i, 0, Q) {
    int l, r, t;
    std::cin >> l >> r >> t;
    rep(j, l, r+1){
      arr[j] = t;
    }
  }
  rep(i, 1, N+1) {
    std::cout << arr[i] << '\n';
  }
  return 0;
}