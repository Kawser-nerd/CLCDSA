#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)                                                         
 
using namespace std;
#define ll long long
 
bool al[26];
 
int check(int n){
  for(int i=n; i<26; i++){
    if(!al[i])
      return i;
  }
  return -1;
}
 
int main(){
  string S;
  cin >> S;
  for(int i=0; i<S.size(); i++){
    al[S[i] - 'a'] = true;
  }
 
  int n = 0;
  string O;
  while(al[n] && n < 26){
    n++;
  }
  if(n == 26){
    int m = 25;
    while(check(S[m] - 'a') == -1 && m > -1){
      al[S[m] - 'a'] = false;
      m--;
    }
    if(m == -1){
      O = "-1";
    } else {
      O = S.substr(0, m) + (char)('a' + check(S[m] - 'a'));
    }
  } else {
    O = S + (char)('a' + n);
  }
 
  cout << O << endl;
 
  // for(int i=0; i<26; i++)                                                                                    
  //   cout << al[i] << ' ';                                                                                    
  // cout << endl;                                                                                              
 
  return 0;
}