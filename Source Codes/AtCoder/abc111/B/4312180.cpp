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
   int n;
   cin >> n;
   int i=n;
   for(int i=n; i < 1000; i++){
      if(i % 111 == 0){
         cout << i << endl;
         return 0;
      }
   }

   return 0;
}