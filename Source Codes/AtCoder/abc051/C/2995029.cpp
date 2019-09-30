#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {

  int sx,sy,tx,ty;
  std::cin >>  sx >> sy >> tx >> ty;
  int dx=tx-sx,dy=ty-sy;

  std::cout << string(dy,'U') << string(dx,'R');
  std::cout << string(dy,'D') << string(dx,'L');
  std::cout << "L" << string(dy+1,'U') << string(dx+1,'R') << 'D';
  std::cout << "R" << string(dy+1,'D') << string(dx+1,'L') << 'U';

  return 0;
}