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
   int a, b;
   cin >> a >> b;
   for(int c = 1; c < 4; c++){
      if(not(a*b*c % 2 == 0)){
         cout << "Yes" << endl;
         return 0;
      }
   }
   cout << "No" << endl;

   return 0;
}