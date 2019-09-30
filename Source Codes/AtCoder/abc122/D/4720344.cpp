#include <iostream>
#include <sstream>
#include <stdio.h>
#include<vector>
#include<climits>
#include<algorithm>
#include<bitset>
#include<cmath>
#include<functional>
#include <numeric>
#include <map>
#define FORi(N) for(int i=0;i<N;++i)
#define FORj(N) for(int j=0;j<N;++j)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
ll gcd(ll m,ll n){
  if(n==0)return abs(m);
  return(gcd(n,m%n));
}
void putYN(bool b){
  if(b){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
}
ll hist[4][4][4][100];
//0:A 1:G 2:C 3:T
ll dp(int _1,int _2,int _3,ll num,ll maxnum){
  ll n=0;
  if(maxnum==num)return 1;
  ll h=hist[_1][_2][_3][num];
  if(h!=-1)return h;
  //A??
  n+=dp(_2,_3,0,num+1,maxnum);
  //G
  if(!(_2==0&&_3==2)){
    n+=dp(_2,_3,1,num+1,maxnum);
  	n%=1000000007ll;
  }
  //C
  if(!((_1==0&&_3==1)||(_1==0&&_2==1)||
       (_2==0&&_3==1)||(_2==1&&_3==0))){
    n+=dp(_2,_3,2,num+1,maxnum);
  	n%=1000000007ll;
  }
  //T
  n+=dp(_2,_3,3,num+1,maxnum);
  hist[_1][_2][_3][num]=n;
  return n%1000000007ll;
}
int main(){
  ll N;
  cin>>N;
  for(int i=0;i<4;i++){
  for(int ii=0;ii<4;ii++){
  for(int iii=0;iii<4;iii++){
  for(int iiii=0;iiii<100;iiii++){
    hist[i][ii][iii][iiii]=-1;
  }}}}
    
  cout<<dp(3,3,3,0,N)<<endl;
  return 0;
}