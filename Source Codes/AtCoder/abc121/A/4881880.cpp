#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[]) {
  int H, W, h, w;
  std::cin >> H >> W;
  std::cin >> h >> w;
  std::cout << W * H - (h * W + w * H - h * w) << '\n';
  return 0;
}