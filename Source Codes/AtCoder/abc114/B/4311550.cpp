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
   string s;
   cin >> s;
   string ans;

   // ???????????v_min?????INT_MAX???,
   // ?????????????????????
   int v_min = INF;
   for(int i = 0; i < (int)s.size() -2; i++)
   {
      // stoi(string)?string -> int?
      // substr(????????, ????????+???????i)
      int v = abs(stoi(s.substr(i, 3)) - 753);
      v_min = min(v,v_min);
   }
   cout << v_min << endl;
   return 0;
}