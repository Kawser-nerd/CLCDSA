//???????-std=c++11??????????
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<algorithm>
#include<cstdlib>
#include<stdio.h>
#include<set>
#include<map>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<iomanip>
#include<cctype>
#include<bitset>//putb(9)=0b00000000000000000000000000001001
//#include<utility>
//#include<tuple>//make_tuple(a,b,c)??????get<?>(tuple?)?????

using namespace std;

int main(){
  int n;cin>>n;
  int a=0,d=0;
  for(int i=0;i<n;i++){
    int b;
    cin>>b;
    if(b!=0){
      d++;a+=b;
    }
  }

  if(a%d==0)cout<<a/d<<endl;
  else cout<<a/d+1<<endl;


  return 0;
}