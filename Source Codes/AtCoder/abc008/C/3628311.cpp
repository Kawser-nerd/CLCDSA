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
  int n;cin>>n;
  int num[n];
  for(int i=0;i<n;i++){
    cin>>num[i];
  }
  float sum=0;
  for(int i=0;i<n;i++){
    int a=0;
    for(int j=0;j<n;j++){
      if(i==j)continue;
      if(num[i]%num[j]==0)a++;
    }
    if(a%2==0)sum=sum+(float)(a+2)/(2*a+2);
    if(a%2==1)sum=sum+(float) 1/2;
    //cout<<i<<" "<<a<<" "<<sum<<endl;
  }
  int b=1;
  for(int i=0;i<n;i++){
    b=b*(n-i);
  }
  cout<<fixed<<setprecision(10)<<sum<<endl;


  return 0;
}