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
  int n;cin>>n;vector<int> v;
  for(int i=0;i<n;i++){
    int x;cin>>x;
    v.push_back(x);
  }

  sort(v.begin(),v.end());
  int a=v[n-1];int j=n-2;int b;
  while(1){
    b=v[j];
    if(b!=a)break;
    j--;
  }

  cout<<b<<endl;


  return 0;
}