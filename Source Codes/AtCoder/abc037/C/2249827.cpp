#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <vector>

#define rep(i, s, N) for(int i = s; i < N; i++)
#define Yes(result) if (result) std::cout << "Yes" << '\n'
#define No(result) if (!result) std::cout << "No" << '\n'
#define resetarr(val, arr) for(int i = 0; i < sizeof(arr) / 4; i++){ arr[i] = val;}


int main(int argc, char const *argv[]) {
  long long int sum = 0;
  int N = 200000 , K = 200000;
  long long arr[N];
  std::cin >> N >> K;
  rep(i, 1, N+1) {
    std::cin >> arr[i];
  }
  rep(i, 1, N+1){
    int times = 0;
    int pos = std::min(i, N-i+1);
    if(pos >= K) times = K;
    else times = pos;
    times = std::min(times, N-K+1);
    sum += arr[i] * times;
  }
  std::cout << sum << '\n';

  return 0;
}