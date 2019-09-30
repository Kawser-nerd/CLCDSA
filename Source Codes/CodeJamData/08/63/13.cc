#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

double P;

double lunar(int N, int X){
  vector<vector<double> > dp(33,N+1);
  dp[32][0]=1.;
  for(int i=1; i<=N; i++){
    for(int j=0; j<=32; j++){
      double best=0.;
      for(int k=0; k<=j; k++){
	if(k+j>32) break;
	double t=P*dp[j+k][i-1]+(1-P)*dp[j-k][i-1];
	if(t>best) best=t;
      }
      dp[j][i]=best;
    }
  }
  return dp[X/(1000000/32)][N];
}

void tos(){
  int N;
  int X;
  cin>>N>>P>>X;
  printf("%.7f\n", lunar(N,X));
}

int main(){
  int N;
  cin>>N;
  for(int i=1; i<=N; i++){
    printf("Case #%d: ", i);
    //cout<<"Case #"<<i<<": ";
    tos();
  }
  return 0;
}

