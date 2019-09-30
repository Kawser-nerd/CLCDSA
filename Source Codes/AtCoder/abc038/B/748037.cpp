#define _USE_MATH_DEFINES
#include <vector>
#include <string>
#include <cmath>
#include <utility>
#include <iostream>

using namespace std;
struct Size {
  int Width, Height;
};

int main() {
  Size a, b;
  cin >> a.Height >> a.Width >> b.Height >> b.Width;
  if (a.Height == b.Height || a.Height == b.Width || a.Width == b.Height || a.Width == b.Width) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
  return 0;
}