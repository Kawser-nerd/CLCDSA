#include <iostream>
#include <string>

int main() {
  int sx, sy, tx, ty;
  std::cin >> sx >> sy >> tx >> ty;

  int dx = tx-sx;
  int dy = ty-sy;

  std::string res;

  // s -> t
  res += std::string(dx, 'R');
  res += std::string(dy, 'U');

  // t -> s
  res += std::string(dx, 'L');
  res += std::string(dy, 'D');

  // s -> t
  res += 'D';
  res += std::string(dx+1, 'R');
  res += std::string(dy+1, 'U');
  res += 'L';

  // t -> s
  res += 'U';
  res += std::string(dx+1, 'L');
  res += std::string(dy+1, 'D');
  res += 'R';

  std::cerr << res.length() << std::endl;
  std::cout << res << std::endl;
}