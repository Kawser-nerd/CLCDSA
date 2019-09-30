#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<climits>
#include<cstdlib>
#include<map>
#include<math.h>
#include<utility>
#include<vector>
using namespace std ;
typedef long long ll;

// N K
// A_1, ..., A_N
int main(){
  string S ;
  cin >> S ;
  int a, b, c, d;

  a = S[0] - '0' ;
  b = S[1] - '0' ;
  c = S[2] - '0' ;
  d = S[3] - '0' ;

  for(int i=0; i<2; ++i){
    for(int j=0; j<2; ++j){
      for(int k=0; k<2; ++k){
        int sum = a ;
        char opt1 ;
        char opt2 ;
        char opt3 ;

        if(i==0){
          sum += b ;
          opt1 = '+';
        }else{
          sum -= b ;
          opt1 = '-';
        }

        if(j==0){
          sum += c ;
          opt2 = '+';
        }else{
          sum -= c ;
          opt2 = '-';
        }

        if(k==0){
          sum += d ;
          opt3 = '+';
        }else{
          sum -= d ;
          opt3 = '-';
        }

        if(sum==7){
          cout << a << opt1 << b << opt2 << c << opt3 << d << "=7" << endl ;
          return 0;
        }
      }
    }
  }
}