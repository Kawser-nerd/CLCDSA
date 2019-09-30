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
//#include<utility>
//#include<tuple>//make_tuple(a,b,c)??????get<?>(tuple?)?????

using namespace std;

int main(){
  int a,b,c,d,t,v,n;
  cin>>a>>b>>c>>d>>t>>v>>n;
  int x[n],y[n];
  for(int i=0;i<n;i++){
    cin>>x[i]>>y[i];
  }
  bool flag=false;

  for(int i=0;i<n;i++){
    double dis=(double)sqrt(pow(a-x[i],2)+pow(b-y[i],2))+sqrt(pow(c-x[i],2)+pow(d-y[i],2));
    if(dis/v<=t)flag=true;
  }

  if(flag==true)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;


  return 0;
}