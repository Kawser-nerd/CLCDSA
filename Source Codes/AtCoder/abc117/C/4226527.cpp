#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<queue>
#include<vector>
#include<utility>
#include<functional>
#include<algorithm>
typedef long long ll;
using namespace std;

vector<int> X;
vector<int> Y;

int main(){
  int N,M,ans;
  cin >> N >> M;
  for(int i=0;i<M;i++){
    int tmp;
    cin >>tmp;
    X.push_back(tmp);
  }
  sort(X.begin(),X.end());
  /*int min = 10000000;
  for(int i=0;i<M-N;i++){
    if(min >= X[N + i] - X[i]){
      min = X[N + i] - X[i];
    }
  }
  cout << min+1 << endl;*/
  if(N>=M){
    ans = 0;
    cout << ans << endl;
  }else{
    for(int i=0;i<M-1;i++){
      int tmp = X[i+1] - X[i];
      Y.push_back(tmp);
      //cout << tmp << endl;
    }
    sort(Y.begin(),Y.end());
    //cout << Y[M-2] << endl;
    int sum = 0;
    for(int i=M-N;i<M-1;i++){
      //cout << Y[i] << endl;
      sum += Y[i];
    }
    cout << X[M-1] - X[0] - sum << endl;
  }
  return 0;
  //?????
}