#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <deque>
#define INF_INT (INT_MAX / 2)
#define INF_LONG (LONG_MAX / 2)
//#define DEBUG true
#define DEBUG false
using namespace std;

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef pair< ll, int > pli;
typedef pair< int, ll > pil;

int ceil(int x, int y){
  return (x % y == 0) ? x / y : x / y + 1;
}

int gcd(int x, int y){
  return y ? gcd(y, x % y) : x;
}

int lcm(int x, int y){
  return x / gcd(x, y) * y;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  int x3 = (x2 - x1) - (y2 - y1) + x1;
  int y3 = (y2 - y1) + (x2 - x1) + y1;
  int x4 = -(y2 - y1) + x1;
  int y4 = (x2 - x1) + y1;

  cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;

  return 0;
}