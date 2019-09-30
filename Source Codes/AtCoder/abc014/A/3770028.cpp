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
  int c=a%b;
  //cout<<c<<endl;
  if(a<b)cout<<b-a<<endl;
  else if(a==b)cout<<"0"<<endl;
  else cout<<b-c<<endl;


  return 0;
}