#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))


int main(){
   int x1, y1, x2, y2;
   cin >> x1 >> y1 >> x2 >> y2;
   int x = x2-x1;
   int y = y2-y1;

   int x3 = x2 - y;
   int y3 = y2 + x;
   int x4 = x1 - y;
   int y4 = y1 + x;
   printf("%d %d %d %d\n", x3, y3, x4, y4);
   return 0;
}