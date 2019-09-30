#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <cctype>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <set>
#include <queue>

using namespace std;

typedef long double real;
typedef long long TT;

#define PB push_back
#define SQR(x) ((x)*(x))
#define PII pair<int, int>
#define VI vector<int>
#define VVI vector<VI >
#define VS vector<string>
#define VTT vector<TT>
#define VR vector<real>
#define A first
#define B second

TT gcd(TT a, TT b)
{
   while (a) {
      TT t = a;
      a = b % a;
      b = t;
   }
   return b;
}

TT mabs(TT a)
{
   return a < 0 ? -a : a;
}

int main()
{
   freopen("input.txt" ,"rt", stdin); freopen("output.txt", "wt", stdout);
   
   int T, sc;
   cin >> T;
   for (sc = 0; sc < T; sc++) {
      int i, n;
      cin >> n;
      VTT a;
      for (i = 0; i < n; i++) {TT t; cin >> t; a.PB(t);}
      VTT b;
      for (i = 1; i < n; i++) b.PB(mabs(a[i] - a[i-1]));
      TT g = b[0];
      for (i = 1; i < b.size(); i++) g = gcd(g, b[i]);
      TT ans = a[0] % g;
      if (ans) ans = g-ans;
      cout << "Case #" << sc+1 << ": ";
      cout << ans;
      cout << endl;
   }
   

   fclose(stdin); fclose(stdout);
   return 0;   
}