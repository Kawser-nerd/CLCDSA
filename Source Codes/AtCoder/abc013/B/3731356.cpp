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
//#include<utility>
//#include<tuple>//make_tuple(a,b,c)??????get<?>(tuple?)?????

using namespace std;

int main(){
  int a,b;
  cin>>a>>b;
  if(a<b)swap(a,b);
  //cout<<"a="<<a<<"   "<<"b?"<<b<<endl;

  int c=10-a;
  if(abs(a-b)>abs(b+c))cout<<b+c<<endl;
  else cout<<a-b<<endl;


  return 0;
}