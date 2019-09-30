#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <limits>
#include <algorithm>
#include <map>
#include <sstream>
#include <unordered_map>
#include <set>

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
static ull tenq = 1000000000;
static ull mod = tenq + 7;

using namespace std;

int main()
{
  ll sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;

  // s to t
  for (auto i = sy; i < ty; i++) cout << "U";
  for (auto i = sx; i < tx; i++) cout << "R";

  // t to s
  for (auto i = ty; i > sy; i--) cout << "D";
  for (auto i = tx; i > sx; i--) cout << "L";

  // s to t
  cout << "L";
  for (auto i = sy; i <= ty; i++) cout << "U";
  for (auto i = sx-1; i < tx; i++) cout << "R";
  cout << "D";

  // t to s
  cout << "R";
  for (auto i = ty; i >= sy; i--) cout << "D";
  for (auto i = tx+1; i > sx; i--) cout << "L";
  cout << "U";

  return 0;
}