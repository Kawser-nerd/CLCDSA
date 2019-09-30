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
   int K;
   cin >> K;
   int sum = 0;
   for(int i=1; i<=K; i++){
      for(int j=0; j<= K; j++){
         if((i % 2 == 0)and(j % 2 != 0)){
            sum++;
         }
      }
   }
   cout << sum << endl;
   return 0;
}