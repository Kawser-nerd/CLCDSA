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

int gcd(const int& a, const int& b){
   const int& _a = max(a,b);
   const int& _b = min(a,b);
   if(_a % _b == 0){
      return _b;
   }
   else{
      return gcd(_b, _a % _b);
   }
}

int lcm(const int& a, const int& b){
   const int& _a = max(a,b);
   const int& _b = min(a,b);
   return (_a*_b)/(gcd(_a, _b));
}

int main(){
   int N;
   cin >> N;
   for(int i=0; i <= N/4; i++){
      for(int j=0; j <= N/7; j++){
         if(4*i + 7*j == N){
            cout << "Yes" << endl;
            return 0;
         }
      }
   }
   cout << "No" << endl;

   return 0;
}