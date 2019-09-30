//https://atcoder.jp/contests/abc122/tasks/abc122_b
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int max2(int a, int b){
  if(a>b) return a;
  else return b;
}

int main(){

  string S;
  cin >> S;
  int ans = 0;
  int len = S.length();
  for(int i=0; i<len; i++){
    for(int j=i; j<len; j++){
      int count=0;
      for(int n=i; n<=j; n++){
        if(S[n]=='A'||S[n]=='T'||S[n]=='G'||S[n]=='C'){
          count++;
        }
      }
      if(count == j-i+1){
        ans = max2(ans,count);
      }
    }
  }
  cout << ans << endl;

  return 0;
}