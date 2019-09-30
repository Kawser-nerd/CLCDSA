#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <vector>

#define rep(i, s, N) for(int i = s; i < N; i++)
#define YesNo(result) do {if (result) std::cout << "YES" << '\n'; else std::cout << "NO" << '\n';} while(0)
#define resetarr(val, arr) for(int i = 0; i < sizeof(arr) / 4; i++){ arr[i] = val; }

int main(int argc, char const *argv[]) {
  int a, b, c, d;
  std::cin >> a >> b;
  std::cin >> c >> d;
  YesNo(a == c || a == d || b == c || b == d);
  return 0;
}