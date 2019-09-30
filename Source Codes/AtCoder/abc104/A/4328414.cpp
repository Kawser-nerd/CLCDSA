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

int GCD(const int& a, const int& b){
   const int& _a = max(a,b);
   const int& _b = min(a,b);
   if(_a % _b == 0){
      return _b;
   }
   else{
      return GCD(_b, _a % _b);
   }
}

int LCM(const int& a, const int& b){
   const int& _a = max(a,b);
   const int& _b = min(a,b);
   return (_a*_b)/(GCD(_a, _b));
}

int main(){
   int r;
   cin >> r;
   if(r < 1200){
      cout << "ABC" << endl;
   }
   else if(r >= 1200 && r < 2800){
      cout << "ARC" << endl;
   }
   else{
      cout << "AGC" << endl;
   }

   return 0;
}