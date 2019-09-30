#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
  int N, x;
  std::cin >> N >> x;
  std::vector<int> v;
  for (int i=0; i<N; ++i) {
    int a;
    std::cin >> a;
    v.push_back(a);
  }
  
  std::sort(v.begin(), v.end(), std::less<int>());
//  for (int i=0; i<N; ++i) std::cout << " " << v[i]; std::cout << std::endl;
  int sum =0;
  for (int i=0; i<N; ++i) {
	sum += v[i];
    if (sum == x) {
      std::cout << i+1 << std::endl;
      return 0;
    }
    if (sum > x) {
      std::cout << i << std::endl;
      return 0;
    }
  }
  std::cout << N-1 << std::endl;
}