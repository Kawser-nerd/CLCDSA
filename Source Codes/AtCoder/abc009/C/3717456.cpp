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
  int n,k;
  string s,t,u;
  cin>>n>>k>>s;
  t=s;

  for(int i=0;i<n;i++){
    int x=i;
    for(int j=i+1;j<n;j++){
      if(t[x]>t[j]){
        u=t;
        swap(u[i],u[j]);
        int cnt=0;
        for(int l=0;l<n;l++)  if(s[l]!=u[l]) cnt++;
        if(cnt<=k)x=j;
          }
        }
        swap(t[i],t[x]);
      }

      cout<<t<<endl;
      return 0;
}