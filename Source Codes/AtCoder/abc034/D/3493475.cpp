#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>

int main(){
  int n, k;
  int w[1005], p[1005];
  double u, l, x, sum;
  std::vector<double> sort;
  std::cin >> n >> k;
  for(int i = 0; i < n; i++){
    std::cin >> w[i] >> p[i];
  }

  u = 0.0;
  l = 100.0;
  while(l - u > 0.0000000001){
    x = (l + u) / 2;
    sum = 0.0;
    sort.clear();

    for(int i = 0; i < n; i++){
      sort.push_back((p[i] - x) * w[i]);
    }
    std::sort(sort.begin(), sort.end(), std::greater<double>());

    for(int i = 0; i < k; i++){
      sum += sort[i];
    }

    if(sum > 0) u = x;
    else l = x;
  }
  std::cout << std::setprecision(10) << u << std::endl;
}