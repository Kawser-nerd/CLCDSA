#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>


#define INF 1000000002486618624LL
#define MOD 1000000007
#define ALL(x) std::begin(x), std::end(x)


bool check(int X, int Y, int R, int x, int y)
{
  int dx = x - X, dy = y - Y;

  return dx * dx + dy * dy <= R * R;
}


int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int x1, y1, r, x2, y2, x3, y3;
  
  std::cin >> x1 >> y1 >> r >> x2 >> y2 >> x3 >> y3;

  std::string answer1("YES"), answer2("YES");

  if (std::min(x2, x3) <= x1 - r && x1 + r <= std::max(x2, x3) &&
      std::min(y2, y3) <= y1 - r && y1 + r <= std::max(y2, y3))

    answer1 = "NO";

  if (check(x1, y1, r, x2, y2) &
      check(x1, y1, r, x2, y3) &
      check(x1, y1, r, x3, y2) &
      check(x1, y1, r, x3, y3))

    answer2 = "NO";

  std::cout << answer1 << std::endl;
  std::cout << answer2 << std::endl;

  return 0;
}