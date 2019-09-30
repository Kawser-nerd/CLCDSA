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
  int a,b,c;cin>>a>>b>>c;
  if(a+b==c&&a-b==c)cout<<"?"<<endl;
  else if(a+b==c)cout<<"+"<<endl;
  else if(a-b==c)cout<<"-"<<endl;
  else cout<<"!"<<endl;

  return 0;
}