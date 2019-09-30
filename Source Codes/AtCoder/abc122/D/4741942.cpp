//https://atcoder.jp/contests/abc122/tasks/abc122_d
#include<iostream>
#include<string.h>
using namespace std;
const long mod=1e9+7;
long N,memo[110][6][6][6][6];

//A=0,G=1,C=2,T=3
long judge(int now,int b3,int b2,int b1,int b){
  if(memo[now][b3][b2][b1][b]!=-1) return memo[now][b3][b2][b1][b];
  if(b3==0&&b2==1&&b==2) return 0;// AG?C???
  if(b3==0&&b1==1&&b==2) return 0;// A?CG???
  if(b2==0&&b1==1&&b==2) return 0;// ?AGC???
  if(b2==0&&b1==2&&b==1) return 0;// ?ACG???
  if(b2==1&&b1==0&&b==2) return 0;// ?GAC???
  if(now==N)return 1;
  //?????????
  long ans=0;
  for(int i=0;i<4;i++){
    ans+=judge(now+1,b2,b1,b,i);
  }
  return memo[now][b3][b2][b1][b]=ans%mod;
}
int main(){
  cin>>N;
  memset(memo,-1,sizeof(memo));
  cout<<judge(0,3,3,3,3)<<endl;
}