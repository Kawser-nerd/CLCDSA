#include <iostream>
#include <cstdio>
#include <cctype>
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
   string S;
   cin >> S;
   bool flag1 = true, flag2 = false;
   if(S[0] == 'A'){
      flag1 = false;
   }
   int cnt_topper_c = 0;
   for(int i=2; i < S.size()-1; i++){
      if(S[i] == 'C'){
         cnt_topper_c++;
      }
   }
   for(int i=1; i < S.size(); i++){
      if(not(S[i] == 'C')){
         if(isupper(S[i])){
            flag2 = true;
            break;
         }
      }
   }
   if(cnt_topper_c != 1 or flag1 or flag2){
      cout << "WA" << endl;
   }
   else{
      cout << "AC" << endl;
   }

return 0;
}