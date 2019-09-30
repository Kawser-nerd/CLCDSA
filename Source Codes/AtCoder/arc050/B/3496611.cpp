#include <iostream>

int main(){
  long long r, b, x, y, u, l, k;
  std::cin >> r >> b >> x >> y;
  u = 0;
  l = 1e+18;
  while(l - u > 1){
    k = (u + l) / 2;
    if((r - k) / (x - 1) + (b - k) / (y - 1) >= k && (r - k) >= 0 && (b - k) >= 0) u = k;
    else l = k + (u + l) % 2;
  }
  std::cout << u << std::endl;
}