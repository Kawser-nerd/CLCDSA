#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#define INF_INT (INT_MAX / 2)
#define INF_LONG (LONG_MAX / 2)
//#define DEBUG true
#define DEBUG false
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  s.insert(a, "\"");
  s.insert(b + 1, "\"");
  s.insert(c + 2, "\"");
  s.insert(d + 3, "\"");

  cout << s << endl;

  return 0;
}