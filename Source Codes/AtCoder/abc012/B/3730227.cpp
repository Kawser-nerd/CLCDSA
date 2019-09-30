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
  int n;cin>>n;
  int a,b,c;
  a=n/3600;
  b=(n-3600*a)/60;
  c=n-3600*a-60*b;


  if(a<10)cout<<"0"<<a<<":";
  else cout<<a<<":";
  if(b<10)cout<<"0"<<b<<":";
  else cout<<b<<":";
  if(c<10)cout<<"0"<<c<<endl;
  else cout<<c<<endl;

  return 0;
}