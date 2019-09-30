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
  int a[n+1];
  int b[10]={0};
  int sum=0;
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<n;i++){
    if(a[i]%2==0&&a[i]%3==2)b[i]=1;
    if(a[i]%2==0&&a[i]%3==1)b[i]=1;
    if(a[i]%2==0&&a[i]%3==0)b[i]=3;
    if(a[i]%2!=0&&a[i]%3==2)b[i]=2;
  }
  for(int j=0;j<n;j++)sum+=b[j];
  cout<<sum<<endl;


  return 0;
}