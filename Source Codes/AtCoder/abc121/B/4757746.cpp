//https://atcoder.jp/contests/abc121/tasks/abc121_b
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
  int N,M,C;
  cin >> N >> M >> C;
  int B[22];
  for (int i=0;i<M;i++){
    cin >>B[i];
  }
  int ans=0;
  for (int i=0; i<N; i++){
    int A[22];
    for(int j=0;j<M;j++){
      cin >>A[j];
    }
    int judge=C;
    for(int j=0;j<M;j++){
      judge+=A[j]*B[j];
    }
    if(judge>0)ans+=1;
  }
  cout << ans << endl;
  return 0;
}