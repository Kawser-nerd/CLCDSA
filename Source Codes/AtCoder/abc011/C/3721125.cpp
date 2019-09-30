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
  int n,n1,n2,n3;
  cin>>n>>n1>>n2>>n3;
  int flag=0;
  for(int i=0;i<100;i++){
    if(n==n1||n==n2||n==n3)break;

    if((n-3)!=n1&&(n-3)!=n2&&(n-3)!=n3&&(n-3)>=0){
      n=n-3;
      if(n==0){
        flag=1;
        break;
      }
      continue;
    }
    else if((n-2)!=n1&&(n-2)!=n2&&(n-2)!=n3&&(n-2)>=0){
      n=n-2;
      if(n==0){
        flag=1;
        break;
      }
      continue;
    }
    else if((n-1)!=n1&&(n-1)!=n2&&(n-1)!=n3&&(n-1)>=0){
      n=n-1;
      if(n==0){
        flag=1;
        break;
      }
      continue;
    }
  }

  if(flag==1)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;


  return 0;
}