#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<queue>
#include<utility>
#include<functional>
#include<math.h>
typedef long long ll;
using namespace std;

int memo[100001]={};

int DP(int n){
  if(n==0){
    return 0;
  }
  if(memo[n]>0){
    return memo[n];
  }
  int ans = DP(n-1)+1;
  for(int i=6;i<=n;i*=6){
    ans = min(ans,DP(n-i)+1);
  }
  for(int i=9;i<=n;i*=9){
    ans = min(ans,DP(n-i)+1);
  }
  memo[n] = ans;
  return memo[n];
}

int main(){
  int N;
  cin >> N;
  memo[1]=1;
  cout << DP(N) << endl;
  return 0;
}