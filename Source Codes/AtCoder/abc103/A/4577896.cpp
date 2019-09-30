#include<iostream>
#include<vector>
int main(void) {
  std::vector<int> v;
  for(int i=0; i<3; i++) {
    int x;
    std::cin >> x;
    v.push_back(x);
  }
  std::sort(v.begin(), v.end());
  std::cout << (v[1]-v[0]) + (v[2]-v[1]) << std::endl;
  return 0;
}