#include <iostream>

int main(){
  int n;
  int x[1000], y[1000], c[1000];
  double u, l, max_x, min_x, max_y, min_y;
  std::cin >> n;
  for(int i = 0; i < n; i++){
    std::cin >> x[i] >> y[i] >> c[i];
  }
  u = 0;
  l = 200000000;
  while(l - u > 0.0001){
    max_x = -300000;
    min_x = 300000;
    max_y = -300000;
    min_y = 300000;
    for(int i = 0; i < n; i++){
      max_x = std::max(max_x, x[i] - (u + l) / (c[i] * 2));
      min_x = std::min(min_x, x[i] + (u + l) / (c[i] * 2));
      max_y = std::max(max_y, y[i] - (u + l) / (c[i] * 2));
      min_y = std::min(min_y, y[i] + (u + l) / (c[i] * 2));
    }
    if(min_x - max_x > 0 && min_y - max_y > 0) l = (u + l) / 2;
    else u = (u + l) / 2;
  }
  std::cout << u << std::endl;
}