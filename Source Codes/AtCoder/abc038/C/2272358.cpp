#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <vector>

#define rep(i, s, N) for(int i = s; i < N; i++)
#define YesNo(result) do {if (result) std::cout << "YES" << '\n'; else std::cout << "NO" << '\n';} while(0)
#define resetarr(val, arr) for(int i = 0; i < sizeof(arr) / 4; i++){ arr[i] = val; }

int main(int argc, char const *argv[]) {
  int N = 3010;
  std::cin >> N;
  int arr[N];
  long long ans = N;
  int len = 0;
  bool trigger = false;
  rep(i, 0, N) std::cin >> arr[i];
  rep(i, 1, N) {
    if(arr[i-1] < arr[i]) {
      trigger = true;
      len++;
    } else {
      if(trigger) rep(i, 1, len+1) ans += i;
      len = 0;
      trigger = false;
    }
  }
  rep(i, 1, len+1) ans += i;
  std::cout << ans << '\n';
  return 0;
}