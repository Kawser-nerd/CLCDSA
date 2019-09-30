#include <iostream>

int main()
{
  int x1, x2, dx;
  int y1, y2, dy;
  std::cin >> x1 >> y1 >> x2 >> y2;
  dx = x2 - x1;
  dy = y2 - y1;
  std::cout << (x2 - dy) << " " << (y2 + dx) << " "
	    << (x1 - dy) << " " << (y1 + dx) << std::endl;
  return 0;
}