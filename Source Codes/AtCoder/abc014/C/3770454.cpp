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
  int c[1000002]={0};
  for(int i=0;i<n;i++){
    int a,b;cin>>a>>b;
    c[a]++;c[b+1]--;
  }

  for(int i=1;i<=1000000;i++){
      c[i]=c[i]+c[i-1];
  }
  
  int max=0;
  for(int j=0;j<=1000000;j++){
    if(c[j]>max) max=c[j];
  }

  cout<<max<<endl;

  return 0;
}