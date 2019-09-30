#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

string S;
int ifACGT(char c){
  switch(c){
    case 'A':
    case 'C':
    case 'G':
    case 'T':
      return 1;
    default:
      return 0;
  }
}
int main(){
  cin >> S;
  int results[20] = {};
  int acgtNow = -1;
  int index = 0;
  for(int i = 0; i < S.length(); ++i){
    if(ifACGT(S[i])){
      if(acgtNow){
        results[index]++;
      }else{
        acgtNow = 1;
        index++;
        results[index]++;
      }
    }else{
      acgtNow  = 0;
    }
  }
  int result = 0;
  for(int i = 0; i < 20; ++i){
    if(results[i] >  result){
      result = results[i];
    }
  }

  cout << result << endl;

  return 0;
}