#include <stdio.h>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;
int main(){
  string S;
  cin>>S;
  long long num=0;
  long long numW=0;
  for(long long i=0;i<S.size();++i){
   	if(S[i]=='B'){
      
    }else{
      num+=(i-numW);
  	  ++numW;
    }
  }
  cout<<num<<endl;
  return 0;
}