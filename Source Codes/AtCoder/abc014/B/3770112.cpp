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
#include<bitset>
//#include<utility>
//#include<tuple>//make_tuple(a,b,c)??????get<?>(tuple?)?????

using namespace std;

int main(){
  int n,x;cin>>n>>x;
  int a[32]={0};
  for(int i=0;i<n;i++){
    int bi=x%2;
    a[i]=bi;
    x=x/2;
  }
  //for(int j=0;j<n;j++)cout<<a[j];
  //cout<<endl;
  int b[n];
  for(int j=0l;j<n;j++){
    cin>>b[j];
  }
  int sum=0;
  for(int i=0;i<n;i++){
    if(a[i]==1)sum+=b[i];
  }
  cout<<sum<<endl;

  return 0;
}