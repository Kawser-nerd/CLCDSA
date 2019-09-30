#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

bool lunar(){
  int N;
  cin>>N;
  vector<vector<int> > E(N,N);
  for(int i=0; i<N-1; i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    E[a][b]=E[b][a]=1;
  }
  int M;
  cin>>M;
  vector<vector<int> > F(M,M);
  for(int i=0; i<M-1; i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    F[a][b]=F[b][a]=1;
  }
  vector<int> per(N);
  for(int i=0; i<N; i++){
    per[i]=i;
  }
  do{
    bool f=true;
    for(int i=0; i<M; i++){
      for(int j=0; j<i; j++){
	if(F[i][j]!=E[per[i]][per[j]]){
	  f=false;
	  goto L1;
	}
      }
    }
L1:
    if(f) return true;
  }while(next_permutation(per.begin(),per.end()));
  return false;
}

void tos(){
  if(lunar()) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}

int main(){
  int N;
  cin>>N;
  for(int i=1; i<=N; i++){
    //printf("Case #%d: ", i);
    cout<<"Case #"<<i<<": ";
    tos();
  }
  return 0;
}

