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
  string a;cin>>a;
  for(int i=0;i<a.size();i++){
    if(i==0){
      if(a[i]>='a'&&a[i]<='z'){
        a[i]=a[i]+('A'-'a');
      }
    }
    else{
      if(a[i]>='A'&&a[i]<='Z'){
        a[i]=a[i]-('A'-'a');
      }
    }
  }
  cout<<a<<endl;


  return 0;
}