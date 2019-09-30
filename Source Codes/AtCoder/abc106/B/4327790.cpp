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

   int n;
   cin >> n;
   int ans=0;
   for(int i=1; i <= n; i++){
      int cnt = 0;
      if (not(i % 2 == 0)){
         for(int j=1; j <= i; j++){
            if(i % j == 0){
               cnt++;
            }
         }
      }
      if(cnt == 8){
         ans++;
      }
   }
   cout << ans << endl;

   return 0;
}