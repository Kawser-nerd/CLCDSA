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
#include<bitset>//putb(9)=0b00000000000000000000000000001001
//#include<utility>
//#include<tuple>//make_tuple(a,b,c)??????get<?>(tuple?)?????

using namespace std;
int n,k,t[5][5];

bool dfs(int i,int x){
  if(i==n){
    if(x==0)return 1;
    else return 0;
  }
  for(int j=0;j<k;j++){
    if(dfs(i+1,x^t[i][j])){
      return true;
    }
  }
  return false;
}

int main(){

  cin>>n>>k;
  for(int i=0;i<n;i++){
    for(int j=0;j<k;j++){
        cin>>t[i][j];
    }
  }
  if(dfs(0,0)) cout<<"Found"<<endl;
  else cout<<"Nothing"<<endl;

  return 0;
}