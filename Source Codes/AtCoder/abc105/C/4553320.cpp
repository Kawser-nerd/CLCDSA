#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long int ll;
ll N;
int main(int argc, char const *argv[]) {
  cin >> N;
  ll temp=N;
  string S;
  for(int i=1;i<=60;i++){
    if(temp%(ll)pow(2,i)!=0){
      S.push_back('1');
      temp=temp-(ll)pow(-2,i-1);
    }else{
      S.push_back('0');
    }
  }
  while(S.back()=='0'){
    S.pop_back();
    if(S.empty()){
      S='0';
      break;
    }
  }
  reverse(S.begin(),S.end());
  cout<<S<<endl;
  return 0;
}