#include <iostream>
using namespace std;

int H, W, h, w;

int main() {
  cin >> H >> W >> h >> w;
  cout << (H-h)*(W-w) << endl;
  return 0;
}