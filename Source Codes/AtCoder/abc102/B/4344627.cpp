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

   int n;
   cin >> n;
   vector<int> a;
   for(int i=0; i < n; i++){
      int aaa;
      cin >> aaa;
      a.push_back(aaa);
   }
   sort(a.begin(), a.end());
   cout << abs(a.back() - a[0]) << endl;
   return 0;
}